/*
 * FUN_004c0c9e at 004c0c9e
 * undefined FUN_004c0c9e(void)
 * Address ranges: 004c0c9e-004c0d69
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_004c0c9e(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint local_8;
  
  uVar1 = param_1;
  if (DAT_006b674c == 0) {
    if ((0x60 < (int)param_1) && ((int)param_1 < 0x7b)) {
      uVar1 = param_1 - 0x20;
    }
  }
  else {
    if ((int)param_1 < 0x100) {
      if (DAT_00502f8c < 2) {
        uVar2 = (byte)PTR_DAT_00502d80[param_1 * 2] & 2;
      }
      else {
        uVar2 = FUN_004c3680(param_1,2);
      }
      if (uVar2 == 0) {
        return uVar1;
      }
    }
    if ((PTR_DAT_00502d80[((int)uVar1 >> 8 & 0xffU) * 2 + 1] & 0x80) == 0) {
      param_1 = CONCAT31((int3)(param_1 >> 8),(char)uVar1) & 0xffff00ff;
      uVar4 = 1;
    }
    else {
      uVar2 = param_1 >> 0x10;
      param_1._0_2_ = CONCAT11((char)uVar1,(char)(uVar1 >> 8));
      param_1 = CONCAT22((short)uVar2,(undefined2)param_1) & 0xff00ffff;
      uVar4 = 2;
    }
    iVar3 = FUN_004c345c(DAT_006b674c,0x200,&param_1,uVar4,&local_8,3,0,1);
    if (iVar3 != 0) {
      if (iVar3 == 1) {
        uVar1 = local_8 & 0xff;
      }
      else {
        uVar1 = local_8 & 0xffff;
      }
    }
  }
  return uVar1;
}

