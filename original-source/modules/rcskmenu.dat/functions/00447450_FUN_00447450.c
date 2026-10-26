/*
 * FUN_00447450 at 00447450
 * undefined __register FUN_00447450(int param_1, int * param_2)
 * Address ranges: 00447450-00447492
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00447450(int param_1,int *param_2)

{
  int *piVar1;
  
  FUN_00403b50(param_2);
  if (*(int *)(param_1 + 4) != 0) {
    if (*(int *)(*(int *)(param_1 + 4) + 8) == 0) {
      piVar1 = FUN_0040ad20((int *)&DAT_004070f4,'\x01',(undefined4 *)PTR_PTR_0047c7b8);
      FUN_00403604(piVar1);
    }
    FUN_00403ba4(param_2,*(undefined4 **)(*(int *)(param_1 + 4) + 8));
  }
  return;
}

