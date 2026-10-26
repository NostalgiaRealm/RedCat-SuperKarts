/*
 * FUN_0042bbb8 at 0042bbb8
 * undefined __register FUN_0042bbb8(int * param_1, uint param_2, undefined4 param_3)
 * Address ranges: 0042bbb8-0042bbf9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042bbb8(int *param_1,uint param_2,undefined4 param_3)

{
  undefined4 extraout_ECX;
  char cVar1;
  
  cVar1 = (char)param_2;
  if ((*(byte *)(param_1 + 0xb3) & 1) == 0) {
    if ((cVar1 != '\0') && (cVar1 != *(char *)((int)param_1 + 0x47))) {
      FUN_0042ca6c(param_1);
      param_3 = extraout_ECX;
    }
    FUN_0043f564(param_1,param_2,param_3);
  }
  else {
    if (cVar1 == '\0') {
      *(byte *)(param_1 + 0xb3) = *(byte *)(param_1 + 0xb3) & 0xfd;
      return;
    }
    *(byte *)(param_1 + 0xb3) = *(byte *)(param_1 + 0xb3) | 2;
  }
  return;
}

