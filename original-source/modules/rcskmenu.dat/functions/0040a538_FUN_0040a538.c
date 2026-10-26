/*
 * FUN_0040a538 at 0040a538
 * undefined __register FUN_0040a538(LCTYPE param_1, int param_2, int param_3, int * param_4, undefined4 param_5, int param_6)
 * Address ranges: 0040a538-0040a572
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040a538(LCTYPE param_1,int param_2,int param_3,int *param_4,undefined4 param_5,int param_6
                 )

{
  FUN_0040a4c4(*(LCID *)(param_6 + -4),param_1,(undefined4 *)0x0,param_4);
  if (*param_4 == 0) {
    FUN_00405438(*(undefined4 **)(param_3 + param_2 * 4),param_4);
  }
  return;
}

