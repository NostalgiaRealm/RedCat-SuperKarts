/*
 * FUN_004449c0 at 004449c0
 * undefined __register FUN_004449c0(int * param_1, int * param_2)
 * Address ranges: 004449c0-004449f1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004449c0(int *param_1,int *param_2)

{
  bool bVar1;
  
  if ((((short)param_2[1] == 1) || ((short)param_2[1] == 2)) &&
     (bVar1 = FUN_00443398((HWND)param_2[2],param_2), bVar1)) {
    return;
  }
  (**(code **)(*param_1 + -0x10))(param_1,param_2);
  return;
}

