/*
 * FUN_004938e0 at 004938e0
 * undefined FUN_004938e0(void)
 * Address ranges: 004938e0-004939cb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004938e0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_1 * 0xd0;
  iVar4 = *(int *)(iVar3 + 0x1c + DAT_0067ee20);
  iVar2 = *(int *)(iVar3 + 0x20 + DAT_0067ee20);
  if (iVar4 == -1) {
    FUN_004afee0(s___s___d_Object_has_illegal_chunk_004fac4c,
                 s_D__work_rcsk_Code_Engine_Prog_If_004faa80,0x221);
  }
  iVar1 = *(int *)(iVar3 + 0x20 + DAT_0067ee20);
  iVar3 = *(int *)(iVar3 + 0x1c + DAT_0067ee20);
  if (((iVar1 < iVar3) && (iVar2 = iVar1, iVar4 = iVar3, iVar1 == 0)) &&
     (iVar3 == DAT_00680b2c + -1)) {
    iVar2 = iVar3;
    iVar4 = 0;
  }
  if (((iVar3 < iVar1) && (iVar2 = iVar3, iVar4 = iVar1, iVar1 == DAT_00680b2c + -1)) &&
     (iVar3 == 0)) {
    iVar2 = iVar1;
    iVar4 = 0;
  }
  if (iVar4 != iVar2) {
    if ((code *)(&DAT_0067fe18)
                [*(int *)(DAT_00680b28 + 0xec + *(int *)(DAT_0068021c + iVar4 * 4) * 0x984)] !=
        (code *)0x0) {
      (*(code *)(&DAT_0067fe18)
                [*(int *)(DAT_00680b28 + 0xec + *(int *)(DAT_0068021c + iVar4 * 4) * 0x984)])
                (param_1);
    }
    if ((code *)(&DAT_0067fe18)
                [*(int *)(DAT_00680b28 + 0xf0 + *(int *)(DAT_0068021c + iVar4 * 4) * 0x984)] !=
        (code *)0x0) {
      (*(code *)(&DAT_0067fe18)
                [*(int *)(DAT_00680b28 + 0xf0 + *(int *)(DAT_0068021c + iVar4 * 4) * 0x984)])
                (param_1);
    }
  }
  return;
}

