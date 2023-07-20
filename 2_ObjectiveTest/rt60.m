% rt60.m

% Step 1: Impulse signal
Fs = 48000;
x = [1 ; zeros(47999,1)];

%audiowrite('impulse.wav',x,Fs);
%stem(x);

% Step 2: Read in measurements
[y1,Fs] = audioread('impulseShort.wav');

% Normalize
y1 = y1/max(abs(y1));

% Convert to dB scale
y1dB = 20*log10(abs(y1));

N = length(y1);
t = [0:N-1].'*(1/Fs);
%plot(t,y1dB);

shortTime = 0.3753 - 0.052


% Step 3: Read in measurements
[y2,Fs] = audioread('impulseLong.wav');

% Normalize
y2 = y2/max(abs(y2));

% Convert to dB scale
y2dB = 20*log10(abs(y2));

N = length(y1);
t = [0:N-1].'*(1/Fs);
plot(t,y2dB);

longTime = 2.742 - 0.0477
