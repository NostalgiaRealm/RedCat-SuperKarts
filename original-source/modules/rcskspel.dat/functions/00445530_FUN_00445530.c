/*
 * FUN_00445530 at 00445530
 * undefined FUN_00445530(void)
 * Address ranges: 00445530-0044561d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

float10 FUN_00445530(float *param_1,int param_2,int param_3)

{
  float fVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  
  if (param_3 < param_2) {
    FUN_004afee0(s___d____s__t__d__bigger_then_numb_004ef3c0,0x109,
                 s_D__work_rcsk_Code_game_pth_main__004ef39c,param_2,param_3);
  }
  fVar1 = (float)param_2 / (float)param_3;
  fVar2 = (float10)FUN_00445620(fVar1,3);
  fVar3 = (float10)FUN_00445620(fVar1,2);
  fVar4 = (float10)FUN_00445620(fVar1,3);
  fVar5 = (float10)FUN_00445620(fVar1,2);
  fVar6 = (float10)FUN_00445620(fVar1,3);
  fVar7 = (float10)FUN_00445620(fVar1,2);
  fVar8 = (float10)FUN_00445620(fVar1,3);
  fVar9 = (float10)FUN_00445620(fVar1,2);
  return (float10)(float)(((float10)(float)(fVar2 + fVar2) - fVar3 * (float10)3.0) + (float10)1.0) *
         (float10)*param_1 +
         (float10)(float)(fVar5 * (float10)3.0 + (float10)(float)(fVar4 * (float10)-2.0)) *
         (float10)param_1[1] +
         (float10)(float)(((float10)(float)fVar6 - (fVar7 + fVar7)) + (float10)fVar1) *
         (float10)param_1[2] + ((float10)(float)fVar8 - fVar9) * (float10)param_1[3];
}

