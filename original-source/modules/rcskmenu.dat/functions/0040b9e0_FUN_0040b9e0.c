/*
 * FUN_0040b9e0 at 0040b9e0
 * undefined __register FUN_0040b9e0(void)
 * Address ranges: 0040b9e0-0040bcaa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040b9e0(void)

{
  LCID LVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int extraout_ECX;
  int extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  int extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  int extraout_ECX_06;
  int extraout_ECX_07;
  int extraout_ECX_08;
  undefined4 extraout_ECX_09;
  byte *unaff_EBX;
  undefined4 *in_FS_OFFSET;
  byte *local_44;
  byte *local_40;
  byte *local_3c;
  char *local_38;
  undefined4 *local_34;
  undefined4 *local_30;
  undefined4 *local_2c;
  undefined4 *local_28;
  undefined4 *local_24;
  byte *pbVar5;
  byte *local_1c;
  byte *local_18;
  undefined4 *local_14;
  undefined4 *local_c;
  undefined4 *local_8;
  
  local_14 = (undefined4 *)&stack0xfffffffc;
  iVar4 = 8;
  do {
    local_8 = (undefined4 *)0x0;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  local_18 = &LAB_0040bcab;
  local_1c = (byte *)*in_FS_OFFSET;
  *in_FS_OFFSET = &local_1c;
  FUN_0040b928();
  FUN_0040a574();
  if (DAT_0047d5b8 != '\0') {
    FUN_0040a74c();
  }
  LVar1 = GetThreadLocale();
  local_24 = (undefined4 *)0x40ba2f;
  FUN_0040a4c4(LVar1,0x14,(undefined4 *)0x0,(int *)&local_14);
  FUN_00403ba4((int *)&DAT_0047d4f0,local_14);
  local_24 = (undefined4 *)0x40ba51;
  FUN_0040a4c4(LVar1,0x1b,(undefined4 *)&DAT_0040bcc0,(int *)&local_18);
  uVar2 = FUN_00407fcc(local_18,0,extraout_ECX);
  DAT_0047d4f4 = (undefined1)uVar2;
  local_24 = (undefined4 *)0x40ba75;
  FUN_0040a4c4(LVar1,0x1c,(undefined4 *)&DAT_0040bcc0,(int *)&local_1c);
  uVar2 = FUN_00407fcc(local_1c,0,extraout_ECX_00);
  DAT_0047d4f5 = (undefined1)uVar2;
  uVar3 = FUN_0040a510(LVar1,0xf,CONCAT31((int3)((uint)extraout_ECX_01 >> 8),0x2c));
  DAT_0047d4f6 = (undefined1)uVar3;
  uVar3 = FUN_0040a510(LVar1,0xe,CONCAT31((int3)((uint)extraout_ECX_02 >> 8),0x2e));
  DAT_0047d4f7 = (undefined1)uVar3;
  pbVar5 = &stack0xffffffe0;
  local_24 = (undefined4 *)0x40babf;
  FUN_0040a4c4(LVar1,0x19,(undefined4 *)&DAT_0040bcc0,(int *)pbVar5);
  uVar2 = FUN_00407fcc(pbVar5,0,extraout_ECX_03);
  DAT_0047d4f8 = (undefined1)uVar2;
  uVar3 = FUN_0040a510(LVar1,0x1d,CONCAT31((int3)((uint)extraout_ECX_04 >> 8),0x2f));
  DAT_0047d4f9 = (undefined1)uVar3;
  local_24 = (undefined4 *)0x40baf6;
  FUN_0040a4c4(LVar1,0x1f,(undefined4 *)"m/d/yy",(int *)&local_28);
  FUN_0040a7fc(local_28,(int *)&local_24);
  FUN_00403ba4(&DAT_0047d4fc,local_24);
  local_24 = (undefined4 *)0x40bb23;
  FUN_0040a4c4(LVar1,0x20,(undefined4 *)"mmmm d, yyyy",(int *)&local_30);
  FUN_0040a7fc(local_30,(int *)&local_2c);
  FUN_00403ba4(&DAT_0047d500,local_2c);
  uVar3 = FUN_0040a510(LVar1,0x1e,CONCAT31((int3)((uint)extraout_ECX_05 >> 8),0x3a));
  DAT_0047d504 = (undefined1)uVar3;
  local_24 = (undefined4 *)0x40bb63;
  FUN_0040a4c4(LVar1,0x28,(undefined4 *)&DAT_0040bcf4,(int *)&local_34);
  FUN_00403ba4(&DAT_0047d508,local_34);
  local_24 = (undefined4 *)0x40bb85;
  FUN_0040a4c4(LVar1,0x29,(undefined4 *)&DAT_0040bd00,(int *)&local_38);
  FUN_00403ba4(&DAT_0047d50c,(undefined4 *)local_38);
  FUN_00403b50((int *)&local_c);
  FUN_00403b50((int *)&stack0xfffffff0);
  local_24 = (undefined4 *)0x40bbb7;
  FUN_0040a4c4(LVar1,0x25,(undefined4 *)&DAT_0040bcc0,(int *)&local_3c);
  iVar4 = FUN_00407fcc(local_3c,0,extraout_ECX_06);
  if (iVar4 == 0) {
    FUN_00403be8((int *)&local_8,0x40bd0c);
  }
  else {
    FUN_00403be8((int *)&local_8,0x40bd18);
  }
  local_24 = (undefined4 *)0x40bbf6;
  FUN_0040a4c4(LVar1,0x23,(undefined4 *)&DAT_0040bcc0,(int *)&local_40);
  iVar4 = FUN_00407fcc(local_40,0,extraout_ECX_07);
  if (iVar4 == 0) {
    local_24 = (undefined4 *)0x40bc19;
    FUN_0040a4c4(LVar1,0x1005,(undefined4 *)&DAT_0040bcc0,(int *)&local_44);
    iVar4 = FUN_00407fcc(local_44,0,extraout_ECX_08);
    if (iVar4 == 0) {
      FUN_00403be8((int *)&stack0xfffffff0,0x40bd24);
    }
    else {
      FUN_00403be8((int *)&local_c,0x40bd34);
    }
  }
  local_24 = local_8;
  local_28 = (undefined4 *)&DAT_0040bd44;
  local_30 = (undefined4 *)0x40bc60;
  FUN_00403e90(&DAT_0047d510,4);
  local_30 = local_c;
  local_34 = local_8;
  local_38 = ":mm:ss";
  local_40 = (byte *)0x40bc7d;
  local_3c = unaff_EBX;
  FUN_00403e90(&DAT_0047d514,4);
  local_40 = (byte *)0x40bc8b;
  uVar3 = FUN_0040a510(LVar1,0xc,CONCAT31((int3)((uint)extraout_ECX_09 >> 8),0x2c));
  DAT_0047d5f4 = (undefined1)uVar3;
  *in_FS_OFFSET = local_3c;
  local_34 = (undefined4 *)&LAB_0040bcb2;
  local_38 = (char *)0x40bcaa;
  FUN_00403b74((int *)&local_44,0x10);
  return;
}

