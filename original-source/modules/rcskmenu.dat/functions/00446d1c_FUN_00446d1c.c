/*
 * FUN_00446d1c at 00446d1c
 * undefined __register FUN_00446d1c(int param_1, undefined4 param_2, undefined * param_3, LPRECT param_4)
 * Address ranges: 00446d1c-00446d74
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00446d1c(int param_1,undefined4 param_2,undefined *param_3,LPRECT param_4)

{
  uint uVar1;
  LPCSTR lpchText;
  HDC hdc;
  int cchText;
  LPRECT lprc;
  
  FUN_0040ebe8(0,0,param_2,&param_4->left,0);
  uVar1 = FUN_00441578(param_1);
  uVar1 = uVar1 | 0xc10;
  cchText = -1;
  lprc = param_4;
  lpchText = FUN_00403f94(param_3);
  hdc = (HDC)FUN_00418994(*(int **)(param_1 + 0x1f0));
  DrawTextA(hdc,lpchText,cchText,lprc,uVar1);
  param_4->right = param_4->right + 6;
  param_4->bottom = param_4->bottom + 2;
  return;
}

