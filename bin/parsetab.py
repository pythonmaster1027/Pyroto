
# parsetab.py
# This file is automatically generated. Do not edit.
# pylint: disable=W,C,R
_tabversion = '3.10'

_lr_method = 'LALR'

_lr_signature = 'DIVIDE EQUAL IF1 IF2 LKAKKO LNAMI MINUS NAME NUMBER PLUS RKAKKO RNAMI STA TIMESexpr : NAME NAME EQUAL NAMEexpr : NAME NAME PLUS SENTexpr : NAME NAME EQUAL NAME PLUS NAMEexpr : NAME NAME EQUAL NAME MINUS NAMEexpr : NAME NAME EQUAL NAME DIVIDE NAMEexpr : NAME NAME EQUAL NAME TIMES NAMEexpr : NAME NAME MINUS SENTexpr : NAME NAMESENT : exprexpr : NAME NAME LKAKKO NAME RKAKKO LNAMIexpr : NAME NAME IF1 NAME LNAMIexpr : NAME NAME IF2 NAME LNAMIexpr : NAME NAME EQUAL EQUAL NAME LNAMIexpr : NAME NAME LNAMIexpr : NAME LKAKKO NAME RKAKKOexpr : NUMBER'
    
_lr_action_items = {'NAME':([0,2,5,6,7,8,9,11,12,15,23,24,25,26,],[2,4,13,14,2,2,19,20,21,27,31,32,33,34,]),'NUMBER':([0,7,8,],[3,3,3,]),'$end':([1,3,4,10,14,16,17,18,22,29,30,31,32,33,34,35,36,],[0,-16,-8,-14,-1,-2,-9,-7,-15,-11,-12,-3,-4,-5,-6,-13,-10,]),'LKAKKO':([2,4,],[5,9,]),'EQUAL':([4,6,],[6,15,]),'PLUS':([4,14,],[7,23,]),'MINUS':([4,14,],[8,24,]),'IF1':([4,],[11,]),'IF2':([4,],[12,]),'LNAMI':([4,20,21,27,28,],[10,29,30,35,36,]),'RKAKKO':([13,19,],[22,28,]),'DIVIDE':([14,],[25,]),'TIMES':([14,],[26,]),}

_lr_action = {}
for _k, _v in _lr_action_items.items():
   for _x,_y in zip(_v[0],_v[1]):
      if not _x in _lr_action:  _lr_action[_x] = {}
      _lr_action[_x][_k] = _y
del _lr_action_items

_lr_goto_items = {'expr':([0,7,8,],[1,17,17,]),'SENT':([7,8,],[16,18,]),}

_lr_goto = {}
for _k, _v in _lr_goto_items.items():
   for _x, _y in zip(_v[0], _v[1]):
       if not _x in _lr_goto: _lr_goto[_x] = {}
       _lr_goto[_x][_k] = _y
del _lr_goto_items
_lr_productions = [
  ("S' -> expr","S'",1,None,None,None),
  ('expr -> NAME NAME EQUAL NAME','expr',4,'p_mov','main.py',67),
  ('expr -> NAME NAME PLUS SENT','expr',4,'p_add','main.py',76),
  ('expr -> NAME NAME EQUAL NAME PLUS NAME','expr',6,'p_addandmov','main.py',82),
  ('expr -> NAME NAME EQUAL NAME MINUS NAME','expr',6,'p_subandmov','main.py',91),
  ('expr -> NAME NAME EQUAL NAME DIVIDE NAME','expr',6,'p_divandmov','main.py',96),
  ('expr -> NAME NAME EQUAL NAME TIMES NAME','expr',6,'p_timandmov','main.py',101),
  ('expr -> NAME NAME MINUS SENT','expr',4,'p_sub','main.py',106),
  ('expr -> NAME NAME','expr',2,'p_msg','main.py',112),
  ('SENT -> expr','SENT',1,'p_SENT','main.py',118),
  ('expr -> NAME NAME LKAKKO NAME RKAKKO LNAMI','expr',6,'p_define','main.py',123),
  ('expr -> NAME NAME IF1 NAME LNAMI','expr',5,'p_if','main.py',132),
  ('expr -> NAME NAME IF2 NAME LNAMI','expr',5,'p_if2','main.py',138),
  ('expr -> NAME NAME EQUAL EQUAL NAME LNAMI','expr',6,'p_if3','main.py',145),
  ('expr -> NAME NAME LNAMI','expr',3,'p_while','main.py',152),
  ('expr -> NAME LKAKKO NAME RKAKKO','expr',4,'p_call','main.py',158),
  ('expr -> NUMBER','expr',1,'p_expr2NUM','main.py',163),
]
