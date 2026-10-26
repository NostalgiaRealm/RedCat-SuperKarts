/*
 * FUN_00414998 at 00414998
 * undefined __register FUN_00414998(int * param_1, int param_2)
 * Address ranges: 00414998-004149cd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414998(int *param_1,int param_2)

{
  (**(code **)(*param_1 + 0x20))(param_1,param_2,*(undefined4 *)(param_2 + 8),0);
  (**(code **)(*param_1 + 0x10))(param_1,param_2,1);
  FUN_00414e5c(param_2,'\0');
  FUN_00414918((int)param_1,param_2);
  return;
}

