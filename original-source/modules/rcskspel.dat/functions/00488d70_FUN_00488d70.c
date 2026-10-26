/*
 * FUN_00488d70 at 00488d70
 * undefined FUN_00488d70(void)
 * Address ranges: 00488d70-00488e95
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x00488e3c) */
/* WARNING: Removing unreachable block (ram,0x00488e42) */
/* WARNING: Removing unreachable block (ram,0x00488e58) */
/* WARNING: Removing unreachable block (ram,0x00488e5a) */
/* WARNING: Removing unreachable block (ram,0x00488e5c) */

void __thiscall FUN_00488d70(int *param_1,int param_2,float *param_3)

{
  int iVar1;
  float *pfVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iStack_14;
  undefined1 auStack_c [12];
  
  if ((((DAT_0053ba78 != 0) && (DAT_0053b9b0 == 0)) &&
      (iStack_14 = (**(code **)*param_1)(), 0 < iStack_14)) && (-1 < iStack_14 + -1)) {
    iVar5 = (iStack_14 + -1) * 0x17c;
    do {
      iVar1 = FUN_00488400();
      if (((iVar1 == param_2) && (pfVar2 = (float *)FUN_00488410(auStack_c), *pfVar2 == *param_3))
         && ((pfVar2[1] == param_3[1] && (pfVar2[2] == param_3[2])))) {
        iVar1 = *(int *)(param_1[1] + 4);
        puVar3 = (undefined4 *)(**(code **)(*param_1 + 8))();
        puVar6 = (undefined4 *)(iVar1 + iVar5);
        for (iVar4 = 0x5f; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar6 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar6 = puVar6 + 1;
        }
        *(int *)(param_1[1] + 8) = *(int *)(param_1[1] + 8) + -0x17c;
      }
      iVar5 = iVar5 + -0x17c;
      iStack_14 = iStack_14 + -1;
    } while (iStack_14 != 0);
  }
  return;
}

