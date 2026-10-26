/*
 * FUN_0042c93c at 0042c93c
 * undefined __register FUN_0042c93c(int param_1, char param_2)
 * Address ranges: 0042c93c-0042c969
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042c93c(int param_1,char param_2)

{
  bool bVar1;
  
  bVar1 = FUN_0042c930(param_1);
  if (((bool)param_2 != bVar1) && (*(undefined4 *)(param_1 + 0x244) = 0, param_2 != '\0')) {
    *(undefined4 *)(param_1 + 0x244) = *(undefined4 *)(DAT_0047d774 + 0x34);
  }
  return;
}

