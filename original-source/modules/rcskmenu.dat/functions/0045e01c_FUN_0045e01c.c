/*
 * FUN_0045e01c at 0045e01c
 * undefined __register FUN_0045e01c(int param_1, undefined4 param_2)
 * Address ranges: 0045e01c-0045e048
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045e01c(int param_1,undefined4 param_2)

{
  char cVar1;
  
  cVar1 = (char)param_2;
  if (cVar1 != *(char *)(param_1 + 0x218)) {
    if (*(int *)(param_1 + 0x208) != 0) {
      FUN_00453528(*(int *)(param_1 + 0x208),param_1,
                   CONCAT31((int3)((uint)param_2 >> 8),*(char *)(param_1 + 0x218)),cVar1);
    }
    *(char *)(param_1 + 0x218) = cVar1;
  }
  return;
}

