/*
 * FUN_004415a4 at 004415a4
 * undefined __register FUN_004415a4(int param_1, int param_2)
 * Address ranges: 004415a4-004415cd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004415a4(int param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  
  piVar1 = *(int **)(param_1 + 0x5c);
  if (piVar1 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar1 + 0x60))(piVar1,*(int *)(param_2 + 8) + 0x38);
    if (cVar2 == '\0') {
      *(undefined4 *)(param_2 + 0xc) = 1;
    }
  }
  return;
}

