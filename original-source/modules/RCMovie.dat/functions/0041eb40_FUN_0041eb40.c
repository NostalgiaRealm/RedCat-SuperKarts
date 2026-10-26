/*
 * FUN_0041eb40 at 0041eb40
 * undefined FUN_0041eb40(void)
 * Address ranges: 0041eb40-0041ec90
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0041eb40(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piStack_54;
  undefined *puStack_40;
  undefined4 *puStack_3c;
  int *piStack_38;
  
  piStack_38 = *(int **)(param_1 + 9);
  *(int **)(param_1 + 0xd) = piStack_38;
  puStack_3c = (undefined4 *)0x41eb55;
  (**(code **)(*piStack_38 + 4))();
  puStack_40 = &DAT_00429fa8;
  puStack_3c = (undefined4 *)(param_1 + 0x11);
  iVar2 = (**(code **)(**(int **)(param_1 + 0xd) + 0x10))();
  if (iVar2 < 0) {
    piStack_54 = (int *)0x41eb7f;
    FUN_004015a6((byte *)s__s__d__Failed_getting_media_stre_00436f14);
    return 0;
  }
  piStack_54 = (int *)0x41eb9c;
  iVar2 = (**(code **)**(undefined4 **)(param_1 + 0x11))();
  if (iVar2 < 0) {
    piStack_54 = (int *)0x13d;
    FUN_004015a6((byte *)s__s__d__Failed_getting_media_stre_00436f14);
    return 0;
  }
  piVar1 = *(int **)(param_1 + 0x1d);
  if (piVar1 != (int *)0x0) {
    piStack_54 = DAT_0043d75c;
    (**(code **)(*piVar1 + 0x7c))(piVar1);
  }
  piStack_54 = (int *)(param_1 + 0x19);
  iVar2 = (**(code **)(**(int **)(param_1 + 0x15) + 0x34))
                    (*(int **)(param_1 + 0x15),*(undefined4 *)(param_1 + 0x1d),0,1);
  if (iVar2 < 0) {
    FUN_004015a6((byte *)s__s__d__Failed_creating_sample_00436ef4);
    return 0;
  }
  piVar1 = *(int **)(param_1 + 0x19);
  piStack_54 = (int *)0x0;
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x20))(piVar1,&piStack_54,&stack0xffffffb0);
    if (iVar2 < 0) {
      FUN_004015a6((byte *)s__s__d__Failed_getting_surface_00436ed4);
      return 0;
    }
  }
  FUN_0041e850(&puStack_40,(undefined4 *)&stack0xffffffb0);
  FUN_0041f0c0((void *)(param_1 + 0x21),&puStack_40);
  FUN_0041f0e0((void *)(param_1 + 0x21),piStack_54);
  return 1;
}

