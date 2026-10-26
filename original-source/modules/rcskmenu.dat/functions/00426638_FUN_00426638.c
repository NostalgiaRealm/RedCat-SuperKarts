/*
 * FUN_00426638 at 00426638
 * undefined __register FUN_00426638(int param_1, int param_2)
 * Address ranges: 00426638-0042666a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00426638(int param_1,int param_2)

{
  undefined4 extraout_ECX;
  
  if (*(int *)(param_1 + 0x2c) != 0) {
    FUN_0043430c(*(int *)(param_1 + 0x2c),*(int *)(param_1 + 0x28));
  }
  *(int *)(param_1 + 0x2c) = param_2;
  if (param_2 != 0) {
    FUN_00434350(param_2,*(int *)(param_1 + 0x28));
    FUN_00414858(*(int *)(param_1 + 0x2c),param_1,extraout_ECX);
  }
  return;
}

