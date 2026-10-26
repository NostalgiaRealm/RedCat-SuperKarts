/*
 * FUN_00409fe0 at 00409fe0
 * undefined FUN_00409fe0(void)
 * Address ranges: 00409fe0-0040a115
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00409fe0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  iVar4 = param_1 * 0x11c;
  iVar2 = FUN_00411250((&DAT_00503ef0)[param_1 * 0x47],1,*(undefined4 *)(&DAT_00503f10 + iVar4),5,3)
  ;
  if (iVar2 < 0) {
    FUN_004afee0(s_Could_not_initialize_the_world_m_004ded08,iVar2);
  }
  uVar1 = *(undefined4 *)(&DAT_00503f10 + iVar4);
  iVar3 = FUN_004096a0(param_1,iVar2,5,
                       *(undefined4 *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0x24 + DAT_0067ee20)
                       ,local_18,local_c);
  *(int *)(&DAT_00503f10 + iVar4) = iVar3;
  if (iVar3 < 0) {
    *(undefined4 *)(&DAT_00503f30 + iVar4) = 0;
    *(undefined4 *)(&DAT_00503f2c + iVar4) = 0;
    *(undefined4 *)(&DAT_00503f10 + iVar4) = uVar1;
  }
  else if (*(float *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0xa4 + DAT_0067ee20) <=
           *(float *)(*(int *)(&DAT_00503ef8 + iVar4) * 0xd0 + 0xa4 + DAT_0067ee20)) {
    FUN_004010e0(param_1,local_c);
    iVar3 = FUN_00409f30(param_1);
    if (iVar3 != 0) {
      *(undefined4 *)(&DAT_00503f30 + iVar4) = 0x42c80000;
    }
  }
  else {
    *(undefined4 *)(&DAT_00503f30 + iVar4) = 0x42480000;
    *(undefined4 *)(&DAT_00503f2c + iVar4) = 0;
  }
  FUN_00401200(param_1,local_18);
  FUN_004112d0(iVar2);
  return;
}

