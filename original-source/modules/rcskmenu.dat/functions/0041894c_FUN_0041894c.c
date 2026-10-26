/*
 * FUN_0041894c at 0041894c
 * undefined __register FUN_0041894c(int * param_1, int param_2, int param_3, uint param_4)
 * Address ranges: 0041894c-0041898d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041894c(int *param_1,int param_2,int param_3,uint param_4)

{
  COLORREF color;
  
  (**(code **)(*param_1 + 0x10))();
  FUN_00418a68(param_1,5);
  color = FUN_00417210(param_4);
  SetPixel((HDC)param_1[1],param_2,param_3,color);
  (**(code **)(*param_1 + 0xc))();
  return;
}

