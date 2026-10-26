/*
 * FUN_004c152d at 004c152d
 * undefined FUN_004c152d(void)
 * Address ranges: 004c152d-004c1615
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_004c152d(uint param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined *puVar5;
  short sVar6;
  
  piVar3 = param_2;
  uVar2 = param_1;
  sVar6 = (short)param_1;
  if (sVar6 == -1) {
    return 0xffff;
  }
  uVar1 = param_2[3];
  if ((uVar1 & 1) == 0) {
    if ((uVar1 & 0x80) == 0) {
      return 0xffff;
    }
    if ((uVar1 & 2) != 0) {
      return 0xffff;
    }
  }
  if (param_2[2] == 0) {
    FUN_004c88ca(param_2);
  }
  if ((piVar3[3] & 0x40U) == 0) {
    uVar1 = piVar3[4];
    if (uVar1 == 0xffffffff) {
      puVar5 = &DAT_005034d0;
    }
    else {
      puVar5 = (undefined *)((&DAT_006b6a60)[(int)uVar1 >> 5] + (uVar1 & 0x1f) * 8);
    }
    if ((puVar5[4] & 0x80) != 0) {
      iVar4 = FUN_004c8ca0(&param_1,uVar2);
      if (iVar4 == -1) {
        _DAT_006b66e8 = 0x2a;
        return 0xffff;
      }
      if (*piVar3 == piVar3[2]) {
        if (piVar3[1] != 0) {
          return 0xffff;
        }
        *piVar3 = *piVar3 + iVar4;
      }
      if (iVar4 != 1) {
        *piVar3 = *piVar3 + -1;
        *(undefined1 *)*piVar3 = param_1._1_1_;
      }
      *piVar3 = *piVar3 + -1;
      *(undefined1 *)*piVar3 = (undefined1)param_1;
      piVar3[1] = piVar3[1] + iVar4;
      piVar3[3] = piVar3[3] & 0xffffffefU | 1;
      return uVar2 & 0xffff;
    }
  }
  if (*piVar3 == piVar3[2]) {
    if (piVar3[1] != 0) {
      return 0xffff;
    }
    *piVar3 = *piVar3 + 2;
  }
  piVar3[1] = piVar3[1] + 2;
  *piVar3 = *piVar3 + -2;
  piVar3[3] = piVar3[3] & 0xffffffefU | 1;
  *(short *)*piVar3 = sVar6;
  return (uint)*(ushort *)*piVar3;
}

