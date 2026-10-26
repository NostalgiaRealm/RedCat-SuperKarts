/*
 * FUN_0040ab70 at 0040ab70
 * undefined FUN_0040ab70(void)
 * Address ranges: 0040ab70-0040ad5b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040ab70(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  undefined1 auStack_18 [12];
  undefined1 auStack_c [12];
  
  iVar5 = param_1 * 0x11c;
  iVar2 = FUN_00411250((&DAT_00503ef0)[param_1 * 0x47],1,0xffffffff,5,3);
  if (iVar2 < 0) {
    FUN_004afee0(s_Could_not_initialize_the_world_m_004dee58,*(undefined4 *)(&DAT_00503f10 + iVar5),
                 iVar2);
  }
  uVar3 = FUN_00411320(iVar2);
  uVar1 = *(undefined4 *)(&DAT_00503f10 + iVar5);
  iVar4 = FUN_004096a0(param_1,iVar2,5,uVar3,auStack_c,auStack_18);
  *(int *)(&DAT_00503f10 + iVar5) = iVar4;
  if (iVar4 < 0) {
    *(undefined4 *)(&DAT_00503f10 + iVar5) = uVar1;
  }
  else {
    iVar4 = FUN_00404eb0(*(undefined4 *)
                          ((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0x1c + DAT_0067ee20),
                         *(undefined4 *)
                          (*(int *)(&DAT_00503ef8 + iVar5) * 0xd0 + 0x1c + DAT_0067ee20));
    if (iVar4 == 0) {
      FUN_004010e0(param_1,auStack_18);
    }
    else if (*(float *)(*(int *)(&DAT_00503ef8 + iVar5) * 0xd0 + 0xa4 + DAT_0067ee20) <
             *(float *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0xa4 + DAT_0067ee20)) {
      fVar6 = (float10)FUN_0048f4e0();
      fVar6 = fVar6 * (float10)400.0 + (float10)*(float *)(&DAT_00503f30 + iVar5);
      *(float *)(&DAT_00503f30 + iVar5) = (float)fVar6;
      if ((float10)100.0 < fVar6) {
        *(undefined4 *)(&DAT_00503f30 + iVar5) = 0x42c80000;
      }
      *(undefined4 *)(&DAT_00503f2c + iVar5) = 0;
    }
    FUN_00401030(param_1,auStack_c);
  }
  FUN_00414470(param_1);
  FUN_00414750(param_1);
  if (*(float *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0xa4 + DAT_0067ee20) < 0.0) {
    *(undefined4 *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0xa4 + DAT_0067ee20) = 0;
    FUN_004140b0((&DAT_00503ef0)[param_1 * 0x47]);
    *(undefined4 *)(&DAT_00503f30 + iVar5) = 0;
  }
  *(undefined4 *)(&DAT_00503f08 + iVar5) = 0;
  FUN_00413330((&DAT_00503ef0)[param_1 * 0x47]);
  FUN_00412fd0((&DAT_00503ef0)[param_1 * 0x47]);
  FUN_004130e0((&DAT_00503ef0)[param_1 * 0x47]);
  FUN_004112d0(iVar2);
  return;
}

