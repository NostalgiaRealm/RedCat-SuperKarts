/*
 * FUN_00408f20 at 00408f20
 * undefined FUN_00408f20(void)
 * Address ranges: 00408f20-00409014
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00408f20(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < DAT_00543760) {
    piVar2 = &DAT_0053f660;
    do {
      if ((((piVar2[2] == 0xb) && (*(int *)(&DAT_00505120 + param_1 * 0x24) == 0)) && (*piVar2 != 0)
          ) && ((piVar2[0xce] == 0 && (*piVar2 == (&DAT_00505110)[param_1 * 9])))) {
        (&DAT_0050510c)[param_1 * 9] = 6;
        *(int *)(&DAT_0050511c + param_1 * 0x24) = iVar1;
        *(undefined4 *)(&DAT_00505118 + param_1 * 0x24) = 0;
        (&DAT_0053f998)[iVar1 * 0xd0] = 1;
        return CONCAT31((int3)((uint)(iVar1 * 3) >> 8),1);
      }
      if (((piVar2[2] == 0xc) && (*(int *)(&DAT_00505120 + param_1 * 0x24) == 1)) &&
         ((*piVar2 != 0 && ((piVar2[0xce] == 0 && (*piVar2 == (&DAT_00505110)[param_1 * 9])))))) {
        (&DAT_0050510c)[param_1 * 9] = 6;
        *(int *)(&DAT_0050511c + param_1 * 0x24) = iVar1;
        *(undefined4 *)(&DAT_00505118 + param_1 * 0x24) = 0;
        (&DAT_0053f998)[iVar1 * 0xd0] = 1;
        return CONCAT31((int3)((uint)(iVar1 * 0x340) >> 8),1);
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0xd0;
    } while (iVar1 < DAT_00543760);
  }
  return 0;
}

