/*
 * FUN_00483060 at 00483060
 * undefined FUN_00483060(void)
 * Address ranges: 00483060-0048327a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00483060(int param_1,int param_2)

{
  float fVar1;
  float10 fVar2;
  float10 fVar3;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  undefined4 uStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  fVar2 = (float10)FUN_00484a90(0x3f000000,0x40000000);
  fVar1 = *(float *)(param_1 + 0xac);
  fStack_18 = *(float *)(param_1 + 0x1c);
  uStack_14 = *(undefined4 *)(param_1 + 0x20);
  fStack_10 = *(float *)(param_1 + 0x24);
  if (0.0 < *(float *)(param_1 + 0x74)) {
    fVar3 = (float10)FUN_00484a90(-*(float *)(param_1 + 0x74),*(float *)(param_1 + 0x74));
    fStack_18 = (float)((float10)fStack_18 + fVar3);
    fVar3 = (float10)FUN_00484a90(-*(float *)(param_1 + 0x74),*(undefined4 *)(param_1 + 0x74));
    fStack_10 = (float)((float10)fStack_10 + fVar3);
  }
  fStack_24 = *(float *)(param_1 + 0x7c);
  fStack_20 = *(float *)(param_1 + 0x80);
  fStack_1c = *(float *)(param_1 + 0x84);
  if (0.0 < *(float *)(param_1 + 0x78)) {
    fVar3 = (float10)FUN_00484a90(-*(float *)(param_1 + 0x78),*(float *)(param_1 + 0x78));
    fStack_c = (float)(fVar3 * (float10)*(float *)(param_1 + 0xe8));
    fStack_8 = (float)(fVar3 * (float10)*(float *)(param_1 + 0xec));
    fStack_24 = fStack_c + fStack_24;
    fStack_20 = fStack_20 + fStack_8;
    fStack_1c = (float)((float10)fStack_1c + fVar3 * (float10)*(float *)(param_1 + 0xf0));
    fVar3 = (float10)FUN_00484a90(-*(float *)(param_1 + 0x78),*(undefined4 *)(param_1 + 0x78));
    fStack_c = (float)(fVar3 * (float10)*(float *)(param_1 + 0xf4));
    fStack_8 = (float)(fVar3 * (float10)*(float *)(param_1 + 0xf8));
    fStack_24 = fStack_c + fStack_24;
    fStack_20 = fStack_20 + fStack_8;
    fStack_1c = (float)((float10)fStack_1c + fVar3 * (float10)*(float *)(param_1 + 0xfc));
  }
  fVar3 = (float10)FUN_00484a90(0x3f400000,0x3fa00000);
  fStack_24 = (float)((float10)fStack_24 * fVar3);
  fStack_20 = (float)((float10)fStack_20 * fVar3);
  fStack_1c = (float)((float10)fStack_1c * fVar3);
  param_2 = param_2 * 0x5c;
  FUN_004824a0((float)(fVar2 * (float10)fVar1),*(undefined4 *)(param_1 + 0xb0),&fStack_24,&fStack_18
               ,param_1 + 200,param_1 + 0xbc);
  *(undefined1 *)(*(int *)(param_1 + 0x9c) + 0x4c + param_2) = *(undefined1 *)(param_1 + 0xb8);
  *(undefined4 *)(*(int *)(param_1 + 0x9c) + 0x44 + param_2) = *(undefined4 *)(param_1 + 0xb4);
  *(undefined4 *)(*(int *)(param_1 + 0x9c) + 0x50 + param_2) = *(undefined4 *)(param_1 + 0x94);
  return;
}

