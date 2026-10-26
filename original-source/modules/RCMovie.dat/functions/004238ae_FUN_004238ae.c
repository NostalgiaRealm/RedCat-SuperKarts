/*
 * FUN_004238ae at 004238ae
 * undefined __cdecl FUN_004238ae(PEXCEPTION_RECORD param_1, PVOID param_2, undefined4 param_3, undefined4 param_4, int param_5, char param_6, int param_7, PVOID param_8)
 * Address ranges: 004238ae-00423a54
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl
FUN_004238ae(PEXCEPTION_RECORD param_1,PVOID param_2,undefined4 param_3,undefined4 param_4,
            int param_5,char param_6,int param_7,PVOID param_8)

{
  byte *pbVar1;
  PEXCEPTION_RECORD pEVar2;
  bool bVar3;
  undefined3 extraout_var;
  int *piVar4;
  int iVar5;
  int *piVar6;
  uint local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_18 = local_18 & 0xffffff00;
  local_14 = *(int *)((int)param_2 + 8);
  if ((local_14 < -1) || (*(int *)(param_5 + 4) <= local_14)) {
    FUN_004240b2();
  }
  pEVar2 = DAT_0043e458;
  if (param_1->ExceptionCode == 0xe06d7363) {
    if (((param_1->NumberParameters == 3) && (param_1->ExceptionInformation[0] == 0x19930520)) &&
       (param_1->ExceptionInformation[2] == 0)) {
      if (DAT_0043e458 == (PEXCEPTION_RECORD)0x0) {
        return;
      }
      param_3 = DAT_0043e45c;
      local_18 = CONCAT31(local_18._1_3_,1);
      bVar3 = FUN_00425fd2(DAT_0043e458,1);
      if (CONCAT31(extraout_var,bVar3) == 0) {
        FUN_004240b2();
      }
      param_1 = pEVar2;
      if (pEVar2->ExceptionCode != 0xe06d7363) goto LAB_00423a2a;
      if (((pEVar2->NumberParameters == 3) && (pEVar2->ExceptionInformation[0] == 0x19930520)) &&
         (pEVar2->ExceptionInformation[2] == 0)) {
        FUN_004240b2();
      }
    }
    iVar5 = local_14;
    if (((param_1->ExceptionCode == 0xe06d7363) && (param_1->NumberParameters == 3)) &&
       (param_1->ExceptionInformation[0] == 0x19930520)) {
      piVar4 = (int *)FUN_004201f5(param_5,param_7,local_14,&local_8,&local_1c);
      do {
        if (local_1c <= local_8) {
          if (param_6 == '\0') {
            return;
          }
          FUN_00423f83((int)param_1);
          return;
        }
        if ((*piVar4 <= iVar5) && (iVar5 <= piVar4[1])) {
          pbVar1 = (byte *)piVar4[4];
          for (local_10 = piVar4[3]; iVar5 = local_14, 0 < local_10; local_10 = local_10 + -1) {
            piVar6 = *(int **)(param_1->ExceptionInformation[2] + 0xc);
            for (local_c = *piVar6; 0 < local_c; local_c = local_c + -1) {
              piVar6 = piVar6 + 1;
              iVar5 = FUN_00423afd(pbVar1,(byte *)*piVar6,(uint *)param_1->ExceptionInformation[2]);
              if (iVar5 != 0) {
                FUN_00423c0e(param_1,param_2,param_3,param_4,param_5,pbVar1,(byte *)*piVar6,piVar4,
                             param_7,param_8);
                iVar5 = local_14;
                goto LAB_00423a0a;
              }
            }
            pbVar1 = pbVar1 + 0x10;
          }
        }
LAB_00423a0a:
        local_8 = local_8 + 1;
        piVar4 = piVar4 + 5;
      } while( true );
    }
  }
LAB_00423a2a:
  if (param_6 == '\0') {
    FUN_00423a55(param_1,param_2,param_3,param_4,param_5,local_14,param_7,param_8);
    return;
  }
  FUN_0042405c();
  return;
}

