/*
 * FUN_0040e180 at 0040e180
 * undefined FUN_0040e180(void)
 * Address ranges: 0040e180-0040e262
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040e180(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_18 [12];
  undefined1 auStack_c [12];
  
  iVar5 = param_1 * 0x11c;
  iVar2 = FUN_00411250((&DAT_00503ef0)[param_1 * 0x47],1,0xffffffff,5,3);
  if (iVar2 < 0) {
    FUN_004afee0(s__s__d____Could_not_initialize_th_004df0dc,
                 s_D__work_rcsk_Code_game_ai_rcr_ha_004df0ac,0x4a,
                 *(undefined4 *)(&DAT_00503f10 + iVar5),iVar2);
  }
  uVar3 = FUN_00411320(iVar2);
  *(undefined4 *)(&DAT_00503f34 + iVar5) = 0;
  uVar1 = *(undefined4 *)(&DAT_00503f10 + iVar5);
  iVar4 = FUN_0040ed40(param_1,iVar2,5,uVar3,auStack_c,auStack_18);
  *(int *)(&DAT_00503f10 + iVar5) = iVar4;
  if (iVar4 < 0) {
    *(undefined4 *)(&DAT_00503f10 + iVar5) = uVar1;
  }
  else {
    iVar4 = FUN_00409b30(uVar3,(&DAT_00503ef0)[param_1 * 0x47]);
    if (iVar4 == 0) {
      FUN_004010e0(param_1,auStack_18);
    }
    else {
      *(undefined4 *)(&DAT_00503f34 + iVar5) = 1;
    }
  }
  FUN_00401200(param_1,auStack_c);
  FUN_004112d0(iVar2);
  return;
}

