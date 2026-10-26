/*
 * FUN_00455b00 at 00455b00
 * undefined FUN_00455b00(void)
 * Address ranges: 00455b00-00455cd9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00455b00(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  float10 fVar5;
  undefined1 *puVar6;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  undefined1 auStack_34 [52];
  
  cVar1 = FUN_00417e90(param_2);
  iVar4 = DAT_0053be28;
  if (cVar1 == '\0') {
    iVar4 = (&DAT_005081bc)[param_2 * 0x1c];
  }
  iVar2 = FUN_004500b0();
  if (iVar2 == 1) {
    uVar3 = FUN_004500d0();
    FUN_0048a480(uVar3);
    FUN_0048a890(uVar3);
    cVar1 = FUN_00417e90(*(undefined4 *)(param_1 + 0x24));
    iVar2 = DAT_0053be28;
    if (cVar1 == '\0') {
      iVar2 = (&DAT_005081bc)[*(int *)(param_1 + 0x24) * 0x1c];
    }
    FUN_00487950(iVar2);
    FUN_00487c00(iVar2);
  }
  uVar3 = FUN_0044fbc0();
  uVar3 = FUN_0044fb50(uVar3);
  FUN_00456ad0(uVar3);
  FUN_0040c820(*(undefined4 *)(param_1 + 0x20),param_1 + 4);
  iVar4 = iVar4 * 0xd0;
  FUN_0040c9c0(iVar4 + 0x9c + DAT_0067ee20);
  FUN_0040c9e0(DAT_006a5c38 + *(int *)(iVar4 + 0xc + DAT_0067ee20) * 0xa9 + 0x74);
  iVar4 = iVar4 + DAT_0067ee20;
  uVar3 = FUN_0044fbc0();
  uVar3 = FUN_0044fb50(uVar3);
  fVar5 = (float10)FUN_00456a30(uVar3);
  fStack_40 = (float)(fVar5 * (float10)*(float *)(iVar4 + 0x9c));
  fStack_3c = (float)(fVar5 * (float10)*(float *)(iVar4 + 0xa0));
  fStack_38 = (float)(fVar5 * (float10)*(float *)(iVar4 + 0xa4));
  FUN_0040ca00(&fStack_40);
  cVar1 = FUN_00417e90(param_2);
  puVar6 = auStack_34;
  if (cVar1 == '\0') {
    FUN_0040d310(param_2,puVar6);
    cVar1 = FUN_00417e90(*(undefined4 *)(param_1 + 0x20));
    if (cVar1 != '\0') {
      FUN_004363e0();
      FUN_00430610(4);
    }
  }
  else {
    FUN_00435a30();
    FUN_00435aa0(puVar6);
    cVar1 = FUN_00417e90(*(undefined4 *)(param_1 + 0x20));
    if (cVar1 == '\0') {
      FUN_0040de60(*(undefined4 *)(param_1 + 0x20));
    }
  }
  FUN_00456440(1);
  return;
}

