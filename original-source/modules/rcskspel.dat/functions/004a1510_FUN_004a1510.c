/*
 * FUN_004a1510 at 004a1510
 * undefined FUN_004a1510(void)
 * Address ranges: 004a1510-004a1643
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a1510(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  float10 fVar4;
  float10 fVar5;
  undefined1 auStack_40 [64];
  
  iVar1 = FUN_004a1440(param_1);
  if (iVar1 == 0) {
    FUN_004afee0(s_nb_table_entries___d__moet_een_m_004fc948,param_1);
  }
  _DAT_004fc8f4 = (float)param_1;
  DAT_004fc8f0 = param_1;
  DAT_004fc8f8 = param_1 + -1;
  DAT_006a5c88 = LocalAlloc(0x40,param_1 * 4);
  if (DAT_006a5c88 == (HLOCAL)0x0) {
    FUN_004afee0(s__s__d____error_allocating_cos_si_004fc8fc,s_D__work_libs_DX3D_Math3d_cpp_004fc928
                 ,0x6f);
  }
  DAT_006a5cd0 = LocalAlloc(0x40,DAT_004fc8f0 * 4);
  if (DAT_006a5cd0 == (HLOCAL)0x0) {
    FUN_004afee0(s__s__d____error_allocating_cos_si_004fc8fc,s_D__work_libs_DX3D_Math3d_cpp_004fc928
                 ,0x73);
  }
  param_1 = 0;
  if (0 < DAT_004fc8f0) {
    do {
      fVar4 = (float10)param_1;
      param_1 = param_1 + 1;
      fVar5 = (float10)fsin((fVar4 / (float10)DAT_004fc8f0) * (float10)6.2831855);
      *(float *)((int)DAT_006a5c88 + param_1 * 4 + -4) = (float)fVar5;
      fVar4 = (float10)fcos((fVar4 / (float10)DAT_004fc8f0) * (float10)6.2831855);
      *(float *)((int)DAT_006a5cd0 + param_1 * 4 + -4) = (float)fVar4;
    } while (param_1 < DAT_004fc8f0);
  }
  _DAT_006a5d18 = 1;
  puVar2 = (undefined4 *)FUN_004a1490(auStack_40);
  puVar3 = &DAT_006a5c90;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = (undefined4 *)FUN_004a14e0(auStack_40);
  puVar3 = &DAT_006a5cd8;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}

