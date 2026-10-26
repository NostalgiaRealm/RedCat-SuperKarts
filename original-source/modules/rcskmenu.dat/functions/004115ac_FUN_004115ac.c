/*
 * FUN_004115ac at 004115ac
 * undefined __register FUN_004115ac(int * param_1)
 * Address ranges: 004115ac-004115de
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004115ac(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[5];
  if (iVar1 < 0x41) {
    if (iVar1 < 9) {
      iVar2 = 4;
    }
    else {
      iVar2 = 0x10;
    }
  }
  else {
    iVar2 = iVar1;
    if (iVar1 < 0) {
      iVar2 = iVar1 + 3;
    }
    iVar2 = iVar2 >> 2;
  }
  (**(code **)(*param_1 + 0x28))(param_1,iVar2 + iVar1);
  return;
}

