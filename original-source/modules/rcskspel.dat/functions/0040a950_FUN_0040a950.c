/*
 * FUN_0040a950 at 0040a950
 * undefined FUN_0040a950(void)
 * Address ranges: 0040a950-0040aa8c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040a950(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  undefined4 local_c [2];
  undefined4 local_4;
  
  iVar3 = param_1 * 0x11c;
  *(undefined4 *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0x48 + DAT_0067ee20) = 0;
  local_c[0] = *(undefined4 *)
                (*(int *)(*(int *)(&DAT_00503ef8 + iVar3) * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 +
                 DAT_006a5c38 + 0x50);
  local_4 = *(undefined4 *)
             (DAT_006a5c38 +
              *(int *)(*(int *)(&DAT_00503ef8 + iVar3) * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 + 0x58);
  iVar2 = FUN_00401320((&DAT_00503ef0)[param_1 * 0x47],local_c);
  if ((0x400 < iVar2) && (iVar2 < 0xc00)) {
    FUN_00409db0(param_1);
    *(undefined4 *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0xa4 + DAT_0067ee20) = 0x41200000;
    fVar4 = (float10)FUN_0048f4e0();
    fVar1 = *(float *)(&DAT_00503f04 + iVar3);
    *(float *)(&DAT_00503f04 + iVar3) = (float)(fVar4 + (float10)fVar1);
    if ((float10)3.0 < fVar4 + (float10)fVar1) {
      *(undefined4 *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0xa4 + DAT_0067ee20) = 0;
    }
  }
  FUN_00413330((&DAT_00503ef0)[param_1 * 0x47]);
  FUN_004130e0((&DAT_00503ef0)[param_1 * 0x47]);
  FUN_00412fd0((&DAT_00503ef0)[param_1 * 0x47]);
  return;
}

