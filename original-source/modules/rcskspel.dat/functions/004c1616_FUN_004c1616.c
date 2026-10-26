/*
 * FUN_004c1616 at 004c1616
 * undefined FUN_004c1616(void)
 * Address ranges: 004c1616-004c1702
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall FUN_004c1616(undefined4 param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 local_8;
  
  puVar2 = param_2;
  local_8 = param_1;
  if ((*(byte *)(param_2 + 3) & 0x40) == 0) {
    uVar4 = param_2[4];
    if (uVar4 == 0xffffffff) {
      puVar3 = &DAT_005034d0;
    }
    else {
      puVar3 = (undefined *)((&DAT_006b6a60)[(int)uVar4 >> 5] + (uVar4 & 0x1f) * 8);
    }
    if ((puVar3[4] & 0x80) != 0) {
      piVar1 = param_2 + 1;
      *piVar1 = *piVar1 + -1;
      uVar6 = 1;
      if (*piVar1 < 0) {
        uVar4 = FUN_004c4a82(param_2);
      }
      else {
        uVar4 = (uint)*(byte *)*param_2;
        *param_2 = (byte *)*param_2 + 1;
      }
      if (uVar4 != 0xffffffff) {
        local_8 = CONCAT31(local_8._1_3_,(char)uVar4);
        if ((PTR_DAT_00502d80[(uVar4 & 0xff) * 2 + 1] & 0x80) != 0) {
          piVar1 = puVar2 + 1;
          *piVar1 = *piVar1 + -1;
          if (*piVar1 < 0) {
            uVar4 = FUN_004c4a82(puVar2);
          }
          else {
            uVar4 = (uint)*(byte *)*puVar2;
            *puVar2 = (byte *)*puVar2 + 1;
          }
          if (uVar4 == 0xffffffff) {
            FUN_004c1222((int)(char)local_8,puVar2);
            return 0xffff;
          }
          local_8._0_2_ = CONCAT11((char)uVar4,(char)local_8);
          uVar6 = 2;
        }
        iVar5 = FUN_004c8dec((int)&param_2 + 2,&local_8,uVar6);
        if (iVar5 != -1) {
          return (uint)param_2 >> 0x10;
        }
        _DAT_006b66e8 = 0x2a;
      }
      return 0xffff;
    }
  }
  piVar1 = param_2 + 1;
  *piVar1 = *piVar1 + -2;
  if (*piVar1 < 0) {
    uVar4 = FUN_004c8d08(param_2);
  }
  else {
    uVar4 = (uint)*(ushort *)*param_2;
    *param_2 = (ushort *)*param_2 + 1;
  }
  return uVar4;
}

