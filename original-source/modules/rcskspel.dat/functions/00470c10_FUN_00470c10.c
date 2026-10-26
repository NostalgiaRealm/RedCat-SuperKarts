/*
 * FUN_00470c10 at 00470c10
 * undefined FUN_00470c10(void)
 * Address ranges: 00470c10-00470c41
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_00470c10(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0xc;
  do {
    piVar1 = (int *)*param_1;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    param_1 = param_1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_00470a70();
  FUN_00470530();
  return 1;
}

