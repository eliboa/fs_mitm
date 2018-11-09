# fs_mitm eliboa mod

This modified version of fs.mitm let you randomize redirections to loose files in LayeredFS ([Atmosphere CFW](https://github.com/Atmosphere-NX/Atmosphere), Nintendo Switch).
I only made it because i wanted to be able to randomize musics (BFSTM files) played in Splatoon 2. For example, in the lobby, the same music is played every time.

## How to use ?
Copy/Replace ```fs_mitm.kip``` from this repo to your ```/atmoshpere``` folder.

Create a folder inside ```/atmosphere/titles/<title ID>/``` that contains all the ```*.bfstm files``` you want to randomly play. For example : 

```/atmosphere/titles/0100F8F0000A2000/randomMusic```

Don't worry about filenames.  

Instead of a ```*.bfstm``` loose file you want to redirect, create a ```*.bfstm.redir``` file. For example :

```/atmosphere/titles/0100F8F0000A2000/Sound/Resource/Stream/STRM_Matching_Versus.bfstm.redir```

The ```*.redir``` file must contain the path to the folder to redirect to. For example :

```/randomMusic```

Don't put any carriage return or line feed.

Repeat the operation for any file you want to redirect or folder you want to redirect to.

Launch Atmosphere & play.

## Disclaimer
This is WIP. I only tested it with splatoon 2 (and atmosphere 0.7.4) but it should work with other Nintendo franchises (MK8, BOTW, Arms, etc).

The module allocates enough size in LayeredFS to play the biggest files. It should work for other formats but i never tested it.

**USE WITH CAUTION**
