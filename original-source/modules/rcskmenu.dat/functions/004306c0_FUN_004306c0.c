/*
 * FUN_004306c0 at 004306c0
 * undefined __register FUN_004306c0(int param_1)
 * Address ranges: 004306c0-00430771
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004306c0(int param_1)

{
  BOOL BVar1;
  HFONT pHVar2;
  HGDIOBJ pvVar3;
  LOGFONTA local_194;
  undefined4 local_158 [40];
  LOGFONTA local_b8;
  LOGFONTA local_7c [2];
  
  BVar1 = SystemParametersInfoA(0x1f,0x3c,&local_194,0);
  if (BVar1 == 0) {
    pvVar3 = GetStockObject(0xd);
    FUN_0041788c(*(int **)(param_1 + 0x78),pvVar3);
  }
  else {
    pHVar2 = CreateFontIndirectA(&local_194);
    FUN_0041788c(*(int **)(param_1 + 0x78),pHVar2);
  }
  local_158[0] = 0x154;
  BVar1 = SystemParametersInfoA(0x29,0,local_158,0);
  if (BVar1 == 0) {
    FUN_00417970(*(int **)(param_1 + 0x74),8);
    pvVar3 = GetStockObject(0xd);
    FUN_0041788c(*(int **)(param_1 + 0x7c),pvVar3);
  }
  else {
    pHVar2 = CreateFontIndirectA(local_7c);
    FUN_0041788c(*(int **)(param_1 + 0x74),pHVar2);
    pHVar2 = CreateFontIndirectA(&local_b8);
    FUN_0041788c(*(int **)(param_1 + 0x7c),pHVar2);
  }
  return;
}

