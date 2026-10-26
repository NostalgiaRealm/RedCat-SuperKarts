/*
 * FUN_00494d20 at 00494d20
 * undefined FUN_00494d20(void)
 * Address ranges: 00494d20-00494f3d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00494d20(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iStack_110;
  int iStack_10c;
  int local_108;
  int iStack_104;
  undefined4 auStack_100 [12];
  undefined4 auStack_d0 [12];
  undefined4 local_a0 [16];
  undefined4 auStack_60 [24];
  
  FUN_004bf930(&local_108,4,1,param_1);
  if (0x10 < local_108) {
    FUN_004afee0(s__s__d____Too_many_road_planes____004fb0bc,
                 s_D__work_rcsk_Code_Engine_Prog_Rd_004fafb4,0xe9,local_108,0x10);
  }
  iVar3 = 0;
  if (0 < local_108) {
    puVar2 = local_a0;
    do {
      uVar1 = FUN_0049cbd0(param_1);
      *puVar2 = uVar1;
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar3 < local_108);
  }
  FUN_004bf930(&iStack_110,4,1,param_1);
  if (0x18 < iStack_110) {
    FUN_004afee0(s__s__d____Too_many_land_planes____004fb088,
                 s_D__work_rcsk_Code_Engine_Prog_Rd_004fafb4,0xf8,iStack_110,0x18);
  }
  iVar3 = 0;
  if (0 < iStack_110) {
    puVar2 = auStack_60;
    do {
      uVar1 = FUN_0049cbd0(param_1);
      *puVar2 = uVar1;
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar3 < iStack_110);
  }
  FUN_004bf930(&iStack_10c,4,1,param_1);
  if (0xc < iStack_10c) {
    FUN_004afee0(s__s__d____Too_many_extra_planes___004fb054,
                 s_D__work_rcsk_Code_Engine_Prog_Rd_004fafb4,0x107,iStack_10c,0xc);
  }
  iVar3 = 0;
  if (0 < iStack_10c) {
    puVar2 = auStack_100;
    do {
      uVar1 = FUN_0049cbd0(param_1);
      *puVar2 = uVar1;
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar3 < iStack_10c);
  }
  FUN_004bf930(&iStack_104,4,1,param_1);
  if (0xc < iStack_104) {
    FUN_004afee0(s__s__d____Too_many_rail_planes____004fb020,
                 s_D__work_rcsk_Code_Engine_Prog_Rd_004fafb4,0x117,iStack_104,0xc);
  }
  iVar3 = 0;
  if (0 < iStack_104) {
    puVar2 = auStack_d0;
    do {
      uVar1 = FUN_0049cbd0(param_1);
      *puVar2 = uVar1;
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar3 < iStack_104);
  }
  FUN_00494f40(local_a0,local_108,auStack_60,iStack_110,auStack_100,iStack_10c,auStack_d0,iStack_104
              );
  if (DAT_006a5bac == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__free_all__s__d_004fafe0,
                 s_______Libs_Win3DLib_Include_arra_004fa4c0,0xe6,&DAT_006a5bb4,DAT_006a5ba4,
                 &DAT_006a5bcd);
  }
  iVar3 = 0;
  if (0 < DAT_006a5ba4) {
    do {
      iVar3 = iVar3 + 1;
      *(undefined1 *)(DAT_006a5bb0 + -1 + iVar3) = 0;
    } while (iVar3 < DAT_006a5ba4);
  }
  DAT_006a5ba8 = 0;
  return;
}

