/*
 * FUN_0041e440 at 0041e440
 * undefined4 __cdecl FUN_0041e440(undefined4 param_1)
 * Address ranges: 0041e440-0041e4d0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __cdecl FUN_0041e440(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined1 local_90 [20];
  int iStack_7c;
  int iStack_78;
  int iStack_74;
  int iStack_70;
  int *piStack_1c;
  int *piStack_18;
  
  puVar4 = local_90;
  uStack_94 = 0;
  uStack_98 = 0;
  uStack_9c = 0;
  uStack_a0 = 0x73646976;
  uStack_a4 = param_1;
  uVar1 = AVIStreamOpenFromFileA(local_90);
  if ((int)uVar1 < 0) {
    return uVar1 & 0xffffff00;
  }
  iVar2 = AVIStreamInfoA(puVar4,&uStack_a4,0x8c);
  if (iVar2 < 0) {
    uVar1 = AVIStreamRelease(puVar4);
    return uVar1 & 0xffffff00;
  }
  *piStack_1c = iStack_74 - iStack_7c;
  *piStack_18 = iStack_70 - iStack_78;
  uVar3 = AVIStreamRelease(puVar4);
  return CONCAT31((int3)((uint)uVar3 >> 8),1);
}

