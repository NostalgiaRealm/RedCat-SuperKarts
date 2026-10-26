/*
 * FUN_004479cc at 004479cc
 * undefined FUN_004479cc(void)
 * Address ranges: 004479cc-00447bd8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004479cc(undefined4 *param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int extraout_ECX;
  int extraout_ECX_00;
  char cVar3;
  int iVar4;
  int *piVar5;
  byte bVar6;
  int aiStack_34 [4];
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  char cStack_d;
  int iStack_c;
  byte bStack_5;
  
  bVar6 = 0;
  bStack_5 = (byte)param_3;
  if (*(char *)((int)param_2 + 0x47) != '\0') {
    iVar4 = param_1[0xe];
    if (iVar4 == 0) {
      if (*(int *)(param_1[0x19] + 8) == 0) {
        (**(code **)(*(int *)param_1[5] + 0x40))((int *)param_1[5],&iStack_24);
        (**(code **)(*(int *)param_1[5] + 0x84))((int *)param_1[5],&iStack_24);
        iVar4 = iStack_1c - iStack_24;
        iStack_14 = iStack_18 - iStack_20;
        if (*(char *)(param_1[5] + 0x4c) != '\0') {
          if (iVar4 == 0) {
            iVar4 = FUN_0043f5f0((int)param_2);
          }
          if (iStack_14 == 0) {
            iStack_14 = FUN_0043f5dc((int)param_2);
          }
        }
        FUN_0040ec04(iStack_24,iStack_20,iVar4,aiStack_34,iStack_14);
        piVar2 = aiStack_34;
        piVar5 = &iStack_24;
        for (iVar4 = 4; iVar4 != 0; iVar4 = iVar4 + -1) {
          *piVar5 = *piVar2;
          piVar2 = piVar2 + (uint)bVar6 * -2 + 1;
          piVar5 = piVar5 + (uint)bVar6 * -2 + 1;
        }
        (**(code **)*param_1)(param_1,param_2,&iStack_24);
        FUN_0043f074(param_2,&iStack_24);
        iVar1 = FUN_004471e4((int *)&LAB_0043c5c0,'\x01',(int)param_1);
        iVar4 = param_1[0x19];
        *(int *)(iVar4 + 8) = iVar1;
        *(int *)(iVar1 + 0x14) = iVar4;
        *(int **)(iVar1 + 4) = param_2;
      }
      else {
        if ((bStack_5 == 0) || (bStack_5 == 5)) {
          bStack_5 = 4;
        }
        piVar2 = (int *)FUN_004478c8((int)param_1,(int)param_2,param_3);
        iVar4 = extraout_ECX;
        if (piVar2 != (int *)0x0) {
          FUN_004488b4((int)param_1,piVar2);
          iVar4 = extraout_ECX_00;
        }
        iStack_c = FUN_004478c8((int)param_1,param_4,iVar4);
        cStack_d = *(char *)(bStack_5 + 0x47b9fc);
        iVar4 = FUN_00447208(param_1[0x19]);
        if (iVar4 == 1) {
          iVar4 = param_1[0x19];
          *(char *)(iVar4 + 0x10) = cStack_d;
          if (cStack_d == '\x01') {
            iVar4 = FUN_00447318(*(int *)(iVar4 + 8),'\x02');
            *(int *)(param_1[0x19] + 0x20) = iVar4;
            iVar4 = FUN_00447318(*(int *)(param_1[0x19] + 8),'\x01');
            param_1[0x1a] = iVar4;
          }
          else if (cStack_d == '\x02') {
            iVar4 = FUN_00447318(*(int *)(iVar4 + 8),'\x01');
            *(int *)(param_1[0x19] + 0x20) = iVar4;
            iVar4 = FUN_00447318(*(int *)(param_1[0x19] + 8),'\x02');
            param_1[0x1a] = iVar4;
          }
        }
        iVar4 = FUN_004471e4((int *)&LAB_0043c5c0,'\x01',(int)param_1);
        *(int **)(iVar4 + 4) = param_2;
        if (iStack_c == 0) {
          cVar3 = *(char *)(param_1[0x19] + 0x10);
        }
        else {
          cVar3 = *(char *)(*(int *)(iStack_c + 0x14) + 0x10);
        }
        if (cStack_d == '\0') {
          cStack_d = cVar3;
        }
        if (cVar3 == cStack_d) {
          FUN_00447d64((int)param_1,iVar4,iStack_c,*(char *)(bStack_5 + 0x47ba04));
        }
        else {
          FUN_00447bdc((int)param_1,iVar4,iStack_c,*(char *)(bStack_5 + 0x47ba04),cStack_d);
        }
      }
    }
    else {
      *(int **)(iVar4 + 4) = param_2;
      FUN_00447540(iVar4);
    }
    (**(code **)(*(int *)param_1[5] + 0x74))();
  }
  return;
}

