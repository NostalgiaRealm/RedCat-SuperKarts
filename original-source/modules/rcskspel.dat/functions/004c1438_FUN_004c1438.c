/*
 * FUN_004c1438 at 004c1438
 * undefined FUN_004c1438(void)
 * Address ranges: 004c1438-004c152c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_004c1438(uint param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  byte bVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  
  piVar2 = param_2;
  if ((*(byte *)(param_2 + 3) & 0x40) != 0) {
LAB_004c150a:
    piVar2 = param_2 + 1;
    *piVar2 = *piVar2 + -2;
    if (*piVar2 < 0) {
      param_1 = FUN_004c8b7c(param_1 & 0xffff,param_2);
    }
    else {
      *(undefined2 *)*param_2 = (undefined2)param_1;
      *param_2 = *param_2 + 2;
    }
    return param_1;
  }
  uVar6 = param_2[4];
  if (uVar6 == 0xffffffff) {
    puVar4 = &DAT_005034d0;
  }
  else {
    puVar4 = (undefined *)((&DAT_006b6a60)[(int)uVar6 >> 5] + (uVar6 & 0x1f) * 8);
  }
  if ((puVar4[4] & 0x80) == 0) goto LAB_004c150a;
  iVar5 = FUN_004c8ca0(&param_2,param_1);
  if (iVar5 == -1) {
    _DAT_006b66e8 = 0x2a;
    return 0xffff;
  }
  if (iVar5 == 1) {
    piVar1 = piVar2 + 1;
    *piVar1 = *piVar1 + -1;
    bVar3 = (byte)param_2;
    if (-1 < *piVar1) {
      *(byte *)*piVar2 = (byte)param_2;
LAB_004c14af:
      uVar6 = (uint)(byte)param_2;
      *piVar2 = *piVar2 + 1;
      goto LAB_004c14c0;
    }
  }
  else {
    piVar1 = piVar2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 0) {
      uVar6 = FUN_004c217c((int)(char)(byte)param_2,piVar2);
    }
    else {
      *(byte *)*piVar2 = (byte)param_2;
      *piVar2 = *piVar2 + 1;
      uVar6 = (uint)param_2 & 0xff;
    }
    if (uVar6 == 0xffffffff) {
      return 0xffff;
    }
    piVar1 = piVar2 + 1;
    *piVar1 = *piVar1 + -1;
    bVar3 = param_2._1_1_;
    if (-1 < *piVar1) {
      *(byte *)*piVar2 = param_2._1_1_;
      param_2._0_1_ = param_2._1_1_;
      goto LAB_004c14af;
    }
  }
  uVar6 = FUN_004c217c((int)(char)bVar3,piVar2);
LAB_004c14c0:
  if (uVar6 == 0xffffffff) {
    return 0xffff;
  }
  return param_1 & 0xffff;
}

