/*
 * FUN_00495cb0 at 00495cb0
 * undefined FUN_00495cb0(void)
 * Address ranges: 00495cb0-00495ec7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00495cb0(int param_1,float *param_2,float *param_3)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  float *pfVar5;
  int iVar6;
  float10 fVar7;
  
  fVar2 = *param_2;
  pfVar1 = (float *)(param_1 + 0x30);
  fVar3 = *param_3;
  *pfVar1 = -(*(float *)(param_1 + 0x2c) - param_3[2]) + -(param_2[2] - *(float *)(param_1 + 0x2c));
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(float *)(param_1 + 0x38) =
       (fVar2 - *(float *)(param_1 + 0x24)) + (*(float *)(param_1 + 0x24) - fVar3);
  *(undefined4 *)(param_1 + 0x34) = 0;
  fVar7 = (float10)FUN_00405f40(pfVar1);
  fVar7 = SQRT(fVar7);
  pfVar4 = (float *)FUN_00405f20((float)((float10)*pfVar1 / fVar7),
                                 (float)((float10)*(float *)(param_1 + 0x34) / fVar7),
                                 (float)((float10)*(float *)(param_1 + 0x38) / fVar7));
  *pfVar1 = *pfVar4;
  *(float *)(param_1 + 0x34) = pfVar4[1];
  *(float *)(param_1 + 0x38) = pfVar4[2];
  fVar2 = param_3[1];
  fVar3 = param_3[2];
  pfVar4 = (float *)(param_1 + 0x48);
  *pfVar4 = *param_3 - *(float *)(param_1 + 0x24);
  *(float *)(param_1 + 0x4c) = fVar2 - *(float *)(param_1 + 0x28);
  *(float *)(param_1 + 0x50) = fVar3 - *(float *)(param_1 + 0x2c);
  fVar7 = (float10)FUN_00405f40(pfVar4);
  fVar7 = SQRT(fVar7);
  pfVar5 = (float *)FUN_00405f20((float)((float10)*pfVar4 / fVar7),
                                 (float)((float10)*(float *)(param_1 + 0x4c) / fVar7),
                                 (float)((float10)*(float *)(param_1 + 0x50) / fVar7));
  *pfVar4 = *pfVar5;
  *(float *)(param_1 + 0x4c) = pfVar5[1];
  *(float *)(param_1 + 0x50) = pfVar5[2];
  pfVar5 = (float *)(param_1 + 0x3c);
  *pfVar5 = *(float *)(param_1 + 0x38) * *(float *)(param_1 + 0x4c) -
            *(float *)(param_1 + 0x34) * *(float *)(param_1 + 0x50);
  *(float *)(param_1 + 0x40) =
       *(float *)(param_1 + 0x50) * *pfVar1 - *(float *)(param_1 + 0x38) * *pfVar4;
  *(float *)(param_1 + 0x44) =
       *(float *)(param_1 + 0x34) * *pfVar4 - *(float *)(param_1 + 0x4c) * *pfVar1;
  fVar7 = (float10)FUN_00405f40(pfVar5);
  fVar7 = SQRT(fVar7);
  pfVar4 = (float *)FUN_00405f20((float)((float10)*pfVar5 / fVar7),
                                 (float)((float10)*(float *)(param_1 + 0x40) / fVar7),
                                 (float)((float10)*(float *)(param_1 + 0x44) / fVar7));
  *pfVar5 = *pfVar4;
  *(float *)(param_1 + 0x40) = pfVar4[1];
  *(float *)(param_1 + 0x44) = pfVar4[2];
  *(float *)(param_1 + 0xdc) =
       *pfVar5 * *(float *)(param_1 + 0x24) +
       *(float *)(param_1 + 0x28) * *(float *)(param_1 + 0x40) +
       *(float *)(param_1 + 0x44) * *(float *)(param_1 + 0x2c);
  pfVar4 = (float *)&DAT_006a5c90;
  pfVar5 = (float *)(param_1 + 0x5c);
  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *pfVar5 = *pfVar4;
    pfVar4 = pfVar4 + 1;
    pfVar5 = pfVar5 + 1;
  }
  *(float *)(param_1 + 0x5c) = *pfVar1;
  *(float *)(param_1 + 0x60) = *pfVar1;
  *(float *)(param_1 + 100) = *pfVar1;
  *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(param_1 + 0x84) = *(undefined4 *)(param_1 + 0x50);
  return;
}

