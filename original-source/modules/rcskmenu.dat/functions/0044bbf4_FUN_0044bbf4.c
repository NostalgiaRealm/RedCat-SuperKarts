/*
 * FUN_0044bbf4 at 0044bbf4
 * undefined FUN_0044bbf4(void)
 * Address ranges: 0044bbf4-0044bc4b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044bbf4(int param_1,LPRECT param_2)

{
  int iVar1;
  
  FUN_00441acc();
  InflateRect(param_2,-*(int *)(param_1 + 0x200),-*(int *)(param_1 + 0x200));
  iVar1 = 0;
  if (*(char *)(param_1 + 0x1fa) != '\0') {
    iVar1 = *(int *)(param_1 + 0x1fc);
  }
  if (*(char *)(param_1 + 0x1f9) != '\0') {
    iVar1 = iVar1 + *(int *)(param_1 + 0x1fc);
  }
  InflateRect(param_2,-iVar1,-iVar1);
  return;
}

