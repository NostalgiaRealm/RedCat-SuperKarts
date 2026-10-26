/*
 * FUN_004295d8 at 004295d8
 * undefined1 * __register FUN_004295d8(void)
 * Address ranges: 004295d8-0042966f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * FUN_004295d8(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined4 in_stack_00000004;
  undefined4 in_stack_00000008;
  
  puVar1 = DAT_0047d77c;
  if (DAT_0047d780 == (undefined1 *)0x0) {
    puVar1 = VirtualAlloc((LPVOID)0x0,0x1000,0x1000,0x40);
    *puVar1 = DAT_0047d77c;
    FUN_0040282c((undefined4 *)&DAT_0047b6cc,puVar1 + 1,2);
    iVar2 = FUN_004295d0((int)puVar1 + 5,0x4295b0);
    *(int *)((int)puVar1 + 6) = iVar2;
    puVar3 = (undefined1 *)((int)puVar1 + 10);
    do {
      puVar4 = puVar3;
      *puVar4 = 0xe8;
      iVar2 = FUN_004295d0((int)puVar4,(int)(puVar1 + 1));
      *(int *)(puVar4 + 1) = iVar2;
      *(undefined1 **)(puVar4 + 5) = DAT_0047d780;
      puVar3 = puVar4 + 0xd;
      DAT_0047d780 = puVar4;
    } while ((int)(puVar4 + 0xd) - (int)puVar1 < 0xffc);
  }
  DAT_0047d77c = puVar1;
  puVar3 = DAT_0047d780;
  puVar1 = (undefined4 *)(DAT_0047d780 + 5);
  DAT_0047d780 = (undefined1 *)*(undefined4 *)(DAT_0047d780 + 5);
  *puVar1 = in_stack_00000004;
  *(undefined4 *)(puVar3 + 9) = in_stack_00000008;
  return puVar3;
}

