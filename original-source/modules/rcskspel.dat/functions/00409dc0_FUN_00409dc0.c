/*
 * FUN_00409dc0 at 00409dc0
 * undefined FUN_00409dc0(void)
 * Address ranges: 00409dc0-00409e97
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00409dc0(int param_1)

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
  iVar2 = FUN_00411250(*(undefined4 *)(&DAT_00503ef8 + iVar5),1,
                       *(undefined4 *)(&DAT_00503f10 + iVar5),5,3);
  if (iVar2 < 0) {
    FUN_004afee0(s_Could_not_initialize_the_world_m_004decd0,iVar2);
  }
  uVar3 = FUN_00411320(iVar2);
  uVar1 = *(undefined4 *)(&DAT_00503f10 + iVar5);
  iVar4 = FUN_004096a0(param_1,iVar2,5,uVar3,auStack_18,auStack_c);
  *(int *)(&DAT_00503f10 + iVar5) = iVar4;
  if (iVar4 < 0) {
    *(undefined4 *)(&DAT_00503f30 + iVar5) = 0;
    *(undefined4 *)(&DAT_00503f2c + iVar5) = 0;
    *(undefined4 *)(&DAT_00503f10 + iVar5) = uVar1;
    FUN_00401200(param_1,auStack_18);
  }
  else {
    FUN_004010e0(param_1,auStack_c);
    FUN_00401200(param_1,auStack_18);
  }
  fVar6 = (float10)FUN_0048f4e0();
  *(float *)(&DAT_00503f04 + iVar5) = (float)(fVar6 + (float10)*(float *)(&DAT_00503f04 + iVar5));
  FUN_004112d0(iVar2);
  return;
}

