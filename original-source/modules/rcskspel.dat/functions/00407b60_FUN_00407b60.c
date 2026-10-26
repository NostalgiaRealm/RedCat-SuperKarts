/*
 * FUN_00407b60 at 00407b60
 * undefined FUN_00407b60(void)
 * Address ranges: 00407b60-00407c59
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4
FUN_00407b60(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  float10 extraout_ST0;
  
  iVar2 = DAT_0067ee20;
  iVar3 = 0;
  if (DAT_00505108 != -1) {
    puVar4 = &DAT_00505108;
    do {
      if (0x50580f < (int)puVar4) break;
      piVar1 = puVar4 + 9;
      puVar4 = puVar4 + 9;
      iVar3 = iVar3 + 1;
    } while (*piVar1 != -1);
    if (iVar3 == 0x32) {
      return 0;
    }
  }
  iVar5 = iVar3 * 0x24;
  iVar6 = param_1 * 0xd0;
  (&DAT_00505108)[iVar3 * 9] = param_1;
  (&DAT_0050510c)[iVar3 * 9] = param_3;
  (&DAT_00505110)[iVar3 * 9] = *(undefined4 *)(iVar6 + 0x1c + iVar2);
  *(undefined4 *)(&DAT_00505114 + iVar5) = *(undefined4 *)(&DAT_00505068 + param_2 * 8);
  *(undefined4 *)(&DAT_00505124 + iVar5) = 0;
  *(undefined4 *)(&DAT_00505118 + iVar5) = 0;
  *(undefined4 *)(&DAT_0050511c + iVar5) = param_5;
  *(undefined4 *)(&DAT_00505120 + iVar5) = param_4;
  if ((&DAT_0050506c)[param_2 * 8] == '\a') {
    *(uint *)(&DAT_00505114 + iVar5) = *(uint *)(&DAT_00505114 + iVar5) | 0x2000;
  }
  *(undefined4 *)(iVar6 + 0x48 + iVar2) = 1;
  FUN_004057f0(param_1,&param_1,&param_3);
  FUN_00407a40(param_1,*(undefined4 *)(&DAT_00505114 + iVar5));
  iVar2 = DAT_0067ee20;
  *(float *)(&DAT_00505128 + iVar5) = (float)extraout_ST0;
  *(float *)(iVar6 + 0xa4 + iVar2) = (float)extraout_ST0;
  return 1;
}

