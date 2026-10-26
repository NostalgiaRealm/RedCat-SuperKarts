/*
 * FUN_00406100 at 00406100
 * undefined FUN_00406100(void)
 * Address ranges: 00406100-004062a1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00406100(int param_1,int param_2)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  char cVar6;
  int iVar7;
  float local_4;
  
  if (DAT_0053b9f4 != 0) {
    cVar6 = FUN_00417e90(param_1);
    iVar7 = DAT_0053be28;
    if (cVar6 == '\0') {
      iVar7 = (&DAT_005081bc)[param_1 * 0x1c];
    }
    iVar1 = iVar7 * 0xd0 + 0x9c + DAT_0067ee20;
    fVar4 = *(float *)(iVar7 * 0xd0 + 0x9c + DAT_0067ee20);
    fVar5 = *(float *)(iVar1 + 4);
    local_4 = *(float *)(iVar1 + 8);
    if (((30.0 <= fVar4) || (30.0 <= fVar5)) || (30.0 <= local_4)) {
      iVar7 = DAT_0053b9f4 * 0xc;
      if (-param_2 < *(int *)(&DAT_004d2308 + iVar7) + *(int *)(&DAT_004d230c + iVar7)) {
        fVar3 = (float)((-param_2 - *(int *)(&DAT_004d2308 + iVar7)) /
                       *(int *)(&DAT_004d230c + iVar7));
        *(float *)(&DAT_00503ffc + param_1 * 0x11c) = fVar3;
        fVar3 = fVar3 * *(float *)(&DAT_004d2310 + iVar7);
      }
      else {
        fVar3 = *(float *)(&DAT_004d2310 + iVar7);
        *(undefined4 *)(&DAT_00503ffc + param_1 * 0x11c) = 0x3f800000;
      }
      fVar3 = fVar3 + 1.0;
      local_4 = local_4 * fVar3;
      if (80.0 <= local_4) {
        local_4 = 80.0;
      }
      cVar6 = FUN_00417e90(param_1);
      iVar7 = DAT_0053be28;
      if (cVar6 == '\0') {
        iVar7 = (&DAT_005081bc)[param_1 * 0x1c];
      }
      pfVar2 = (float *)(iVar7 * 0xd0 + 0x9c + DAT_0067ee20);
      *pfVar2 = fVar4 * fVar3;
      pfVar2[1] = fVar5 * fVar3;
      pfVar2[2] = local_4;
      (&DAT_00503ff8)[param_1 * 0x11c] = 1;
    }
  }
  return;
}

