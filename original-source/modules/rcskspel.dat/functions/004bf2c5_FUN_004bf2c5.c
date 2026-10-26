/*
 * FUN_004bf2c5 at 004bf2c5
 * undefined FUN_004bf2c5(void)
 * Address ranges: 004bf2c5-004bf31a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004bf2c5(FILE *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((param_1->_flag & 0x40U) == 0) {
    if ((param_1->_flag & 0x83U) != 0) {
      uVar2 = FUN_004c1305(param_1);
      __freebuf(param_1);
      iVar1 = FUN_004c36f5(param_1->_file);
      if (iVar1 < 0) {
        uVar2 = 0xffffffff;
      }
      else if (param_1->_tmpfname != (char *)0x0) {
        FUN_004bff99(param_1->_tmpfname);
        param_1->_tmpfname = (char *)0x0;
      }
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  param_1->_flag = 0;
  return uVar2;
}

