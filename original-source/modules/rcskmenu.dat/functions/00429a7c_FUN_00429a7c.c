/*
 * FUN_00429a7c at 00429a7c
 * undefined __register FUN_00429a7c(int param_1, undefined4 param_2, undefined4 param_3, int param_4)
 * Address ranges: 00429a7c-00429ade
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00429a7c(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x47) != '\0') {
    cVar1 = *(char *)(param_1 + 0x4b);
    if ((cVar1 == '\0') || (cVar1 == '\x03')) {
      if ((*(char *)(param_1 + 0x4b) == '\x03') || ((*(byte *)(param_1 + 0x51) & 5) == 1)) {
        iVar2 = FUN_0041f444(*(int *)(param_4 + -4),
                             *(int *)(*(int *)(param_4 + -8) + 0xc) + *(int *)(param_1 + 0x30) +
                             *(int *)(param_1 + 0x38));
        *(int *)(param_4 + -4) = iVar2;
      }
    }
    else if (cVar1 == '\x04') {
      *(int *)(param_4 + -0xc) = *(int *)(param_4 + -0xc) + *(int *)(param_1 + 0x38);
    }
  }
  return;
}

