/*
 * FUN_00401dc0 at 00401dc0
 * undefined FUN_00401dc0(void)
 * Address ranges: 00401dc0-00401e9a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00401dc0(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float fStack_4;
  
  if (DAT_0053b9f4 == 0) {
    fStack_4 = DAT_00505034;
  }
  else {
    fStack_4 = DAT_00505038;
  }
  iVar3 = param_1 * 0x11c;
  fVar4 = (float10)FUN_0048f4e0();
  fVar1 = *(float *)(&DAT_00503f04 + iVar3);
  *(float *)(&DAT_00503f04 + iVar3) = (float)(fVar4 + (float10)fVar1);
  if ((float10)fStack_4 < fVar4 + (float10)fVar1) {
    *(undefined4 *)(&DAT_00503f04 + iVar3) = 0;
    FUN_00412c50((&DAT_00503ef0)[param_1 * 0x47],0);
    FUN_0041f870(*(undefined4 *)(&DAT_00503ef8 + iVar3));
    return 1;
  }
  iVar2 = FUN_00493a40(*(undefined4 *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0x1c + DAT_0067ee20)
                       ,*(undefined4 *)
                         (*(int *)(&DAT_00503ef8 + iVar3) * 0xd0 + 0x1c + DAT_0067ee20));
  if (DAT_0050503c < iVar2) {
    FUN_0041f870(*(undefined4 *)(&DAT_00503ef8 + iVar3));
    return 1;
  }
  return 0;
}

