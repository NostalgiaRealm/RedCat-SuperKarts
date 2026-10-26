/*
 * FUN_004c300d at 004c300d
 * undefined FUN_004c300d(void)
 * Address ranges: 004c300d-004c3087
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004c300d(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,int param_7,undefined4 *param_8,undefined4 param_9,
                 int param_10)

{
  int iVar1;
  
  if (param_7 != 0) {
    FUN_004c31be(param_1,param_2,param_6,param_7);
  }
  if (param_10 == 0) {
    param_10 = param_2;
  }
  FUN_004beb26(param_10,param_1);
  FUN_004c2f6f(param_2,param_4,param_5,*param_8);
  *(int *)(param_2 + 8) = param_8[1] + 1;
  iVar1 = FUN_004c3088(param_1,param_2,param_3,param_5,*(undefined4 *)(param_6 + 0xc),param_9,0x100)
  ;
  if (iVar1 != 0) {
    FUN_004beae4(iVar1,param_2);
  }
  return;
}

