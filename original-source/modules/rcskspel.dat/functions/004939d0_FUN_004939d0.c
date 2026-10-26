/*
 * FUN_004939d0 at 004939d0
 * undefined FUN_004939d0(void)
 * Address ranges: 004939d0-00493a17
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004939d0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = &DAT_0067ee78;
  do {
    if (*piVar1 == 0) goto LAB_00493a01;
    piVar1 = piVar1 + 2;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < 0x67fe18);
  FUN_004afee0(s___s___d_No_more_free_entry_s_004fac74,s_D__work_rcsk_Code_Engine_Prog_If_004faa80,
               0x267);
  iVar2 = -1;
LAB_00493a01:
  (&DAT_0067ee78)[iVar2 * 2] = 1;
  (&DAT_0067ee7c)[iVar2 * 2] = param_1;
  return;
}

