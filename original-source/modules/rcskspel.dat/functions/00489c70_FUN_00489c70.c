/*
 * FUN_00489c70 at 00489c70
 * undefined FUN_00489c70(void)
 * Address ranges: 00489c70-00489d18
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x00489c97) */
/* WARNING: Removing unreachable block (ram,0x00489c9a) */
/* WARNING: Removing unreachable block (ram,0x00489cab) */
/* WARNING: Removing unreachable block (ram,0x00489cad) */
/* WARNING: Removing unreachable block (ram,0x00489caf) */
/* WARNING: Removing unreachable block (ram,0x00489ccc) */
/* WARNING: Removing unreachable block (ram,0x00489ccf) */
/* WARNING: Removing unreachable block (ram,0x00489ce0) */
/* WARNING: Removing unreachable block (ram,0x00489ce2) */
/* WARNING: Removing unreachable block (ram,0x00489ce4) */

void __thiscall FUN_00489c70(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)*param_1)();
  if (999 < iVar1 + 2) {
    *(int *)(param_1[1] + 8) = *(int *)(param_1[1] + 8) + -0x20;
    *(int *)(param_1[1] + 8) = *(int *)(param_1[1] + 8) + -0x20;
  }
  FUN_004897e0();
  FUN_004896c0(param_2);
  FUN_00489640();
  return;
}

