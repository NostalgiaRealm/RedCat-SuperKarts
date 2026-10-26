/*
 * FUN_0040a2b0 at 0040a2b0
 * undefined FUN_0040a2b0(void)
 * Address ranges: 0040a2b0-0040a3ab
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040a2b0(int param_1)

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
    FUN_004afee0(s_Could_not_initialize_the_world_m_004ded40,*(undefined4 *)(&DAT_00503f10 + iVar5),
                 iVar2);
  }
  uVar3 = FUN_00411320(iVar2);
  uVar1 = *(undefined4 *)(&DAT_00503f10 + iVar5);
  iVar4 = FUN_004096a0(param_1,iVar2,5,uVar3,auStack_18,auStack_c);
  *(int *)(&DAT_00503f10 + iVar5) = iVar4;
  if (iVar4 < 0) {
    *(undefined4 *)(&DAT_00503f10 + iVar5) = uVar1;
    FUN_00414470(param_1);
    FUN_00414750(param_1);
  }
  else {
    FUN_00401030(param_1,auStack_18);
    FUN_00414470(param_1);
    FUN_00414750(param_1);
  }
  FUN_00413330((&DAT_00503ef0)[param_1 * 0x47]);
  FUN_00412fd0((&DAT_00503ef0)[param_1 * 0x47]);
  FUN_004130e0((&DAT_00503ef0)[param_1 * 0x47]);
  *(undefined4 *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0xa4 + DAT_0067ee20) = 0x418553f8;
  FUN_004112d0(iVar2);
  return;
}

