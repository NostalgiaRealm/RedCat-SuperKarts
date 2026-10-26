/*
 * FUN_0044e464 at 0044e464
 * undefined __register FUN_0044e464(int param_1, int param_2)
 * Address ranges: 0044e464-0044e486
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044e464(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0044e0d0((int *)&PTR_FUN_0044e0a8,'\x01',*(undefined4 **)(param_1 + 0xc),param_2);
  (**(code **)(**(int **)(param_1 + 8) + 0xc))(*(int **)(param_1 + 8),uVar1);
  return;
}

