/*
 * FUN_0048c170 at 0048c170
 * undefined FUN_0048c170(void)
 * Address ranges: 0048c170-0048c2fa;0048c318-0048c32a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_0048c170(int param_1,float param_2,undefined4 param_3,float param_4)

{
  float fVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_004d157a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004afce0(s_respawn_check_for_object__d__pos_004fa078,param_1,(double)param_2,(double)param_4);
  local_8 = 0;
  iVar6 = 0;
  do {
    if (DAT_00508610 + 1 <= iVar6) {
      ExceptionList = local_10;
      return CONCAT31((int3)((uint)(DAT_00508610 + 1) >> 8),1);
    }
    FUN_004afce0(s_Checking_next_opponent__d_004fa0a4,iVar6);
    cVar3 = FUN_00417e90();
    iVar4 = DAT_0053be28;
    if (cVar3 == '\0') {
      iVar4 = (&DAT_005081bc)[iVar6 * 0x1c];
    }
    if (iVar4 != param_1) {
      cVar3 = FUN_00417e90();
      iVar4 = DAT_0053be28;
      if (cVar3 == '\0') {
        iVar4 = (&DAT_005081bc)[iVar6 * 0x1c];
      }
      fVar1 = *(float *)(DAT_006a5c38 + *(int *)(iVar4 * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 + 0x50) -
              param_2;
      cVar3 = FUN_00417e90();
      iVar4 = DAT_0053be28;
      if (cVar3 == '\0') {
        iVar4 = (&DAT_005081bc)[iVar6 * 0x1c];
      }
      fVar2 = *(float *)(DAT_006a5c38 + *(int *)(iVar4 * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 + 0x58) -
              param_4;
      if (fVar1 * fVar1 + fVar2 * fVar2 <= 2000.0) {
        uVar5 = FUN_004afce0();
        ExceptionList = local_10;
        return uVar5 & 0xffffff00;
      }
    }
    iVar6 = iVar6 + 1;
  } while( true );
}

