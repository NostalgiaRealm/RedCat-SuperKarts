/*
 * FUN_00432200 at 00432200
 * undefined __register FUN_00432200(int param_1, undefined4 param_2, uint param_3)
 * Address ranges: 00432200-00432220
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00432200(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  tagMSG tStack_20;
  
  uVar1 = FUN_00432150(param_1,&tStack_20,param_3);
  if ((char)uVar1 == '\0') {
    FUN_00432994(param_1);
  }
  return;
}

