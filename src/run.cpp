#include "main.hpp"

void VM ( map<string, string> func, string funcname, map <string, int> intvall, map <string, string> strvall ) {
    vector<string> vec = split( func[funcname], "3b" ), vec2, vec3;
    map <string, string> strin;
    string vdata, ans, a, b, mode, anser;
    stringstream ss, ss2;

    int y, x, popc=0, callc=0;
    for ( int i = 0; i < vec.size(); i++ ) {
        vdata = vec[i];
        vdata = regex_replace( vdata, regex("22"),"20");
        if ( vdata != "" ) {
            if ( vdata.find( "61646420" ) != string::npos ) {
                a = hextostring( split( split( vdata, "2c" )[0], "61646420" )[1] );
                b = hextostring( split( vdata, "2c20" )[1] );
                ans = split( split( vdata, "2c" )[0], "61646420" )[1];
                if ( intkeyfind( intvall, a ) ) {
                    intvall[ans] = intvall[a] + y;
                }
                else {
                    intvall[ans] = atoi( a.c_str() );
                }
            }
            if ( vdata.find( "6d736720" ) != string::npos ) {
                if ( keyfind( strvall, strpri( split( vdata, "6d736720" )[1] )  ) ) {
                    cout << strvall[ strpri( split( vdata, "6d736720" )[1] ) ] << endl;
                }
                else
                if ( intkeyfind(intvall, strpri( split( vdata, "6d736720" )[1] )  ) ) {
                    cout << intvall[ strpri( split( vdata, "6d736720" )[1] ) ] << endl;
                }
            }

            if ( vdata.find( "6d6f7620" ) != string::npos ) {
                string data, a;
                ans = hextostring( split( split( vdata, "2c20" )[0], "6d6f7620" )[1] );
                a = split( vdata, "2c20" )[1];
                data = strpri( a );
                if( mode == "int" ) {
                    intvall[ans] = atoi( data.c_str() );
                }
                else
                if ( mode == "str" ) {
                    strvall[ans] = data;
                }
            }
            if ( vdata.find( "6d6f64653e" ) != string::npos ) {
                if ( split( vdata, "6d6f64653e" )[1] == "696e74" ) {
                    mode = "int";
                }
                else
                if ( split( vdata, "6d6f64653e" )[1] == "737472" ) {
                    mode = "str";
                }
            }
            if ( vdata.find( "63616c6c" ) != string::npos ) {
                /*
                ? This is "call"
                ？　（　より前の語句のみ格納されている、つまり呼び出しには　（　より前でのみ読み読み込みされれば良い。
                ？　（　よりあとかつ　）　の前での語句のみを独自に読み取り変数の受け渡しに使用
                ？　ただしそれには呼び出し時に引数を記述しなければならない
                ？　⇨　base : callを抜き出したもともとの文字列、呼び出し文
                ？　⇨　func : 呼び出しされる関数名
                ？　⇨　 arg : 受け渡される変数名が加わる文字列
                */
                string arg = split( split( vdata, "5d" )[0], "5b" )[1], arg2;
                vector<string> vec;
                map<string, int>intvall2;
                map<string, string>strvall2;
                if ( arg.find( "2c" ) != string::npos ) {
                    vec = split( arg, "2c" );
                    for ( int i = 0; i < vec.size(); i++ ) {
                        vec[i] = strpri(vec[i]);
                        strvall2[to_string(i)] = strvall[ vec[i] ];
                    }
                }
                else {
                    arg2 = strpri( arg );
                    strvall2 [ to_string( callc ) ] = strvall [arg2];
                    callc++;
                }
                VM( func, split( split( vdata, "63616c6c20" )[1], "5b" )[0], intvall2, strvall2 );
            }
            if ( vdata.find( "6a6e7020" ) != string::npos ) {
                string base, c, badata;
                base = split( vdata, "6a6e7020" )[1];
                c = split( base, "0c20" )[1];
                badata = strpri( vdata );
                if ( intifj( badata, intvall, "jnp" ) == 0 ) {
                    VM( func, c, intvall, strvall );
                }
            }
            if ( vdata.find( "6a6120" ) != string::npos ) {
                string base, c, badata;
                base = split( vdata, "6a6120" )[1];
                c = split( base, "0c20" )[1];
                badata = strpri( vdata );
                if ( intifj( badata, intvall, "ja" ) == 1 ) {
                    VM( func, c, intvall, strvall );
                }
            }
            if ( vdata.find( "6a616520" ) != string::npos ) {
                /*
                ? This is "jae"
                ? a == b { func[c] }
                ? summary : if ( equal )
                ? base : base string
                */
                string base, a, c;
                base = split( vdata, "6a616520" )[1];
                a = strpri( split( base, "2c20" )[0] );
                b = strpri( split( split( base, "2c20" )[1], "0c20" )[0] );
                c = split( base, "0c20" )[1];
                if ( intkeyfind( intvall, a ) ) {
                    if ( intkeyfind( intvall, b ) ) {
                        if ( atoi( a.c_str() ) == atoi( b.c_str() ) ) {
                            VM( func, c, intvall, strvall );
                        }
                    }
                    else 
                    if ( atoi( a.c_str() ) == intvall[b] ) {
                        VM( func, c, intvall, strvall );
                    }
                }                
            }
            if ( vdata.find( "706f7020" ) != string::npos ) {
                // TODO : This is "pop"
                string arg = strpri( split( vdata, "706f7020" )[1]);
                strvall [ arg ] = strvall[ to_string( popc ) ];
                popc++;
            }
            if ( vdata.find( "6a6d7020" ) != string::npos ) {
                /*
                ? this is "while"
                ? name = call function`s name
                ? arg = loop count
                */
                string name = split( split( vdata, "2c" )[0], "20" )[1];
                string arg = strpri( split( vdata, "2c20" )[1] );
                for ( int i = 0; i < atoi( arg.c_str() ); ++i ) {
                    VM( func, name, intvall, strvall );
                }
            }
        }
    }
}

int main( int argc, char **arg ){
    
    ifstream fin( split( arg[1], "." )[0], ios::in | ios::binary );
    string funcname, data;
    vector<string> vec;
    map<string, string> func;
    map <string, string> strvall;
    map <string, int> intvall;
    int hex;

    char buf[16];
    while(!fin.eof()) {
        fin.read(buf,sizeof(16));
        string data2( buf, 4 );
        data += data2;
    }
    vec = split( data, "3b" );
    for ( int i = 0; i < vec.size(); i++ ) {
        vec[i] = vec[i] + "3b";
        if ( vec[i].find("3a") != string::npos ) {
            funcname = split( vec[i], "28" )[0];
            func[funcname] += split( vec[i], "3a" )[1];
        }
        else {
            func[funcname] += vec[i];
        }
    }
    VM( func, "6d61696e", intvall, strvall );
    return 0;
}
