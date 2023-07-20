clc;clear;close all;

% read impluse reponse file
% y :audio data, Fs: sample rate

filename1='IRofV12.wav';

%please change the filename.
[y, Fs]= audioread(filename1);

y1= y(:,1);  % only process the 1st channal
y2= y(:,2);

L= length(y);
T= 1/Fs;    
t= (0:L-1)*T;  % change the number of points to seconds

% fft of impluse response
Y1= fft(y1);
Y2= fft(y2);
% compute amplitude 
P2 = abs(Y1/L);
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);

P4 = abs(Y2/L);
P3 = P4(1:L/2+1);
P3(2:end-1) = 2*P3(2:end-1);


% plot in frequency domain
f = Fs*(0:(L/2))/L; % change the number of points to Hz
figure(1);
subplot(1,2,1);
plot(f,P1);

title('fft of V12, left channel')
xlabel('f(Hz)')
ylabel('Amplitude')


subplot(1,2,2);
plot(f,P3);

title('fft of V12, right channel ')
xlabel('f(Hz)')
ylabel('Amplitude')

%plot in time domain
%y=20*log10(abs(y1)); % logarithmic coordinates

t=(1:0.2*Fs)*T;

figure(3);

subplot(2,1,1);
y1= y1(1: 0.2*Fs)';
plot(t,abs(y1));
 axis([0 0.2 0 0.05]);
title('IR of V12, left channel')
xlabel('time(second)')
ylabel('Amplitude')

subplot(2,1,2); 
y2= y2(1: 0.2*Fs)';
plot(t,abs(y2));
axis([0 0.2 0 0.05]);
title('IR of V12, right channel')
xlabel('time(second)')
ylabel('Amplitude')

