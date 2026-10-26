/*
 * FUN_004c03bd at 004c03bd
 * undefined FUN_004c03bd(void)
 * Address ranges: 004c03bd-004c045d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004c03bd(FILE *param_1,int *param_2,uint param_3,uint param_4)

{
  undefined4 local_8;
  
  local_8 = 0;
  if ((param_3 == 4) ||
     (((1 < param_4 && (param_4 < 0x80000000)) && ((param_3 == 0 || (param_3 == 0x40)))))) {
    param_4 = param_4 & 0xfffffffe;
    FUN_004c1305(param_1);
    __freebuf(param_1);
    *(ushort *)&param_1->_flag = (ushort)param_1->_flag & 0xc2f3;
    if ((param_3 & 4) == 0) {
      if (param_2 == (int *)0x0) {
        param_2 = _malloc(param_4);
        if (param_2 == (int *)0x0) {
          _DAT_006b6740 = _DAT_006b6740 + 1;
          return 0xffffffff;
        }
        *(ushort *)&param_1->_flag = (ushort)param_1->_flag | 0x408;
      }
      else {
        param_1->_flag = param_1->_flag | 0x500;
      }
    }
    else {
      param_1->_flag = param_1->_flag | 4;
      param_2 = &param_1->_charbuf;
      param_4 = 2;
    }
    param_1->_cnt = 0;
    param_1->_bufsiz = param_4;
    param_1->_base = (char *)param_2;
    param_1->_ptr = (char *)param_2;
  }
  else {
    local_8 = 0xffffffff;
  }
  return local_8;
}

